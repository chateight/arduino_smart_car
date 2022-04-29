//**************************************************************************
// FreeRtos on Samd21
// By Scott Briscoe
//
// Project is a simple example of how to get FreeRtos running on a SamD21 processor
// Project can be used as a template to build your projects off of as well
//
//**************************************************************************

#include <FreeRTOS_SAMD21.h>

//**************************************************************************
// Type Defines and Constants
//**************************************************************************

#define ERROR_LED_PIN  13 //Led Pin: Typical Arduino Board

#define ERROR_LED_LIGHTUP_STATE  HIGH // the state that makes the led light up on your board, either low or high

// Select the serial port the project should use and communicate over
// Some boards use SerialUSB, some use Serial
#define SERIAL          SerialUSB //Sparkfun Samd21 Boards

//**************************************************************************
// global variables
//**************************************************************************
TaskHandle_t Handle_aTask;    // web server task
TaskHandle_t Handle_bTask;    // drive task
TaskHandle_t Handle_cTask;    // s_motor gimmick task
TaskHandle_t Handle_monitorTask;  // monitor task
 
//**************************************************************************
// Can use these function for RTOS delays
// Takes into account processor speed
// Use these instead of delay(...) in rtos tasks
//**************************************************************************
void myDelayUs(int us)
{
  // vTaskDealy() is used to move into blockes state
  vTaskDelay( us / portTICK_PERIOD_US );  
}

void myDelayMs(int ms)
{
  vTaskDelay( (ms * 1000) / portTICK_PERIOD_US );  
}

void myDelayMsUntil(TickType_t *previousWakeTime, int ms)
{
  vTaskDelayUntil( previousWakeTime, (ms * 1000) / portTICK_PERIOD_US );  
}

//*****************************************************************
// Create a thread that prints out A to the screen every two seconds
// this task will delete its self after printing out afew messages
//*****************************************************************
QueueHandle_t xQueue = xQueueCreate( 10, sizeof( unsigned long ) );
void threadA( void *pvParameters ) 
{
  boolean run_state_a= false;     // car state false:halt, true:active
  int32_t SendValue = 0;
  BaseType_t xStatus;
  while(1){
    SendValue=web_server_ap();    // ap mode
    //SendValue=web_server();     // wi-fi mode
    if (SendValue<9)
    {
      if (SendValue==1 && run_state_a==false)
      {      // whether to activate or stay at current state?
        xTaskCreate(threadC,     "Task C",       256, NULL, tskIDLE_PRIORITY + 4, &Handle_cTask); 
        run_state_a= true;    // set to run state
        xStatus = xQueueSend(xQueue, &SendValue, 0);
      }     
      else if (SendValue==0 && run_state_a==true)
      {  // whether to halt or stay at
        run_state_a= false;    // set to halt state
        SendValue=0;
        xStatus = xQueueSend(xQueue, &SendValue, 0);
      }
      if(xStatus != pdPASS) // send error check
      {
        while(1)
        {
        Serial.println("rtos queue send error, stopped");
        delay(300);
        }
      }
  // delete ourselves.
  // Have to call this or the system crashes when you reach the end bracket and then get scheduled.
  //vTaskDelete( Handle_bTask );
    }
    myDelayMs(300);
  }
  SERIAL.println("Thread A: Deleting");
  vTaskDelete( NULL );
}

//*****************************************************************
// Create a thread that prints out B to the screen every second
// this task will run forever
//*****************************************************************
void threadB( void *pvParameters ) 
{ 
  BaseType_t xStatus;
  int32_t ReceivedValue = 0;
  const TickType_t xTicksToWait = 500U;
  unsigned int distance;
  boolean run_state_b=false;

  while(1){
      xStatus = xQueueReceive(xQueue, &ReceivedValue, xTicksToWait);

      if(xStatus == pdPASS) // receive error check
         {
             if (ReceivedValue==1){           // run?
              run_state_b= true;
              distance=s_sensor();
              if (distance>30){
              dc_motor(0);
                }
              else{
                dc_motor(1);
                }
              }
             else{
              run_state_b= false;
              dc_motor(2);
              }
         }
      else{
        if (run_state_b==true){
          distance=s_sensor();
          if (distance>30){
              dc_motor(0);
          }
          else{
          dc_motor(1);
          }
        }
      }
//
    SERIAL.flush();
    myDelayMs(50);
  }
}
void threadC( void *pvParameters ) 
{
  s_motor();
  vTaskDelete( NULL );
}

//*****************************************************************
// Task will periodically print out useful information about the tasks running
// Is a useful tool to help figure out stack sizes being used
// Run time stats are generated from all task timing collected since startup
// No easy way yet to clear the run time stats yet
//*****************************************************************
static char ptrTaskList[400]; //temporary string buffer for task stats

void taskMonitor(void *pvParameters)
{
    //int x;
    int measurement;
    
    SERIAL.println("Task Monitor: Started");

    // run this task afew times before exiting forever
    while(1)
    {
    //	myDelayMs(10000); // print every 10 seconds

    	SERIAL.flush();
		  SERIAL.println("");			 
    	SERIAL.println("****************************************************");
    	SERIAL.print("Free Heap: ");
    	SERIAL.print(xPortGetFreeHeapSize());
    	SERIAL.println(" bytes");

    	SERIAL.print("Min Heap: ");
    	SERIAL.print(xPortGetMinimumEverFreeHeapSize());
    	SERIAL.println(" bytes");
    	SERIAL.flush();

    	SERIAL.println("****************************************************");
    	SERIAL.println("Task            ABS             %Util");
    	SERIAL.println("****************************************************");

    	vTaskGetRunTimeStats(ptrTaskList); //save stats to char array
    	SERIAL.println(ptrTaskList); //prints out already formatted stats
    	SERIAL.flush();

		  SERIAL.println("****************************************************");
		  SERIAL.println("Task            State   Prio    Stack   Num     Core" );
		  SERIAL.println("****************************************************");

		  vTaskList(ptrTaskList); //save stats to char array
		  SERIAL.println(ptrTaskList); //prints out already formatted stats
		  SERIAL.flush();

		  SERIAL.println("****************************************************");
		  SERIAL.println("[Stacks Free Bytes Remaining] ");

		  measurement = uxTaskGetStackHighWaterMark( Handle_aTask );
		  SERIAL.print("Thread A: ");
		  SERIAL.println(measurement);

		  measurement = uxTaskGetStackHighWaterMark( Handle_bTask );
		  SERIAL.print("Thread B: ");
		  SERIAL.println(measurement);

		  measurement = uxTaskGetStackHighWaterMark( Handle_monitorTask );
		  SERIAL.print("Monitor Stack: ");
		  SERIAL.println(measurement);

		  SERIAL.println("****************************************************");
		  SERIAL.flush();
      myDelayMs(10000); // print every 10 seconds
    }

    // delete ourselves.
    // Have to call this or the system crashes when you reach the end bracket and then get scheduled.
    SERIAL.println("Task Monitor: Deleting");
    vTaskDelete( NULL );

}


//*****************************************************************

void setup() 
{
  SERIAL.begin(9600);
  delay(1000); // prevents usb driver crash on startup, do not omit this
  //while (!SERIAL) ;  // Wait for serial terminal to open port before starting program
  // sensor initialize
  init_sensor();
  // Wi-Fi initialize
  init_wifi_ap();   // wi-fi ap mode
  //init_wifi();    // wi-fi mode
  // s_motor initialize
  init_s_motor();
  //dc_motor initialize
  init_dc_motor();
  SERIAL.println("");
  SERIAL.println("        Program start         ");
  SERIAL.println("******************************");
  SERIAL.flush();

  // Set the led the rtos will blink when we have a fatal rtos error
  // RTOS also Needs to know if high/low is the state that turns on the led.
  // Error Blink Codes:
  //    3 blinks - Fatal Rtos Error, something bad happened. Think really hard about what you just changed.
  //    2 blinks - Malloc Failed, Happens when you couldn't create a rtos object. 
  //               Probably ran out of heap.
  //    1 blink  - Stack overflow, Task needs more bytes defined for its stack! 
  //               Use the taskMonitor thread to help gauge how much more you need
  vSetErrorLed(ERROR_LED_PIN, ERROR_LED_LIGHTUP_STATE);

  // sets the serial port to print errors to when the rtos crashes
  // if this is not set, serial information is not printed by default
  vSetErrorSerial(&SERIAL);

  // Create the threads that will be managed by the rtos
  // Sets the stack size and priority of each task
  // Also initializes a handler pointer to each task, which are important to communicate with and retrieve info from tasks
  // Low priority numbers denote low priority tasks. 
  xTaskCreate(threadA,     "Task A",       256, NULL, tskIDLE_PRIORITY + 3, &Handle_aTask);
  xTaskCreate(threadB,     "Task B",       256, NULL, tskIDLE_PRIORITY + 2, &Handle_bTask);
  xTaskCreate(taskMonitor, "Task Monitor", 256, NULL, tskIDLE_PRIORITY + 1, &Handle_monitorTask);

  // Start the RTOS, this function will never return and will schedule the tasks.
  vTaskStartScheduler();

  // error scheduler failed to start
  // should never get here
  
  while(1)
  {
	  SERIAL.println("Scheduler Failed! \n");
	  SERIAL.flush();
	  delay(1000);
  }
}

//*****************************************************************
// This is now the rtos idle loop
// No rtos blocking functions allowed!
//*****************************************************************
void loop() 
{
    delay(500); //delay is interrupt friendly, unlike vNopDelayMS
}


//*****************************************************************
