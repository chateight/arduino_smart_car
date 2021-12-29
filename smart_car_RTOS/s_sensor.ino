// # Editor     : roker
// # Date       : 05.03.2018

// # Product name: URM V5.0 ultrasonic sensor
// # Product SKU : SEN0001
// # Version     : 1.0

// # Description:
// # The Sketch for scanning 180 degree area 2-800cm detecting range
// # The sketch for using the URM37 PWM trigger pin mode from DFRobot
// #   and writes the values to the serialport
// # Connection:
// #       Vcc (Arduino)    -> Pin 1 VCC (URM V5.0)
// #       GND (Arduino)    -> Pin 2 GND (URM V5.0)
// #       Pin 6 (Arduino)  -> Pin 4 ECHO (URM V5.0)
// #       Pin 7 (Arduino)  -> Pin 6 COMP/TRIG (URM V5.0)

// # Working Mode: PWM trigger pin  mode.(global variables)

int URECHO = 6;         // PWM Output 0-50000US,Every 50US represent 1cm
int URTRIG = 7;         // trigger pin

void init_sensor()
{
  pinMode(URTRIG, OUTPUT);                   // A low pull on pin COMP/TRIG
  digitalWrite(URTRIG, HIGH);                // Set to HIGH
  pinMode(URECHO, INPUT);                    // Sending Enable PWM mode command
  delay(100);
}
int s_sensor()
{
  unsigned int DistanceMeasured;
  digitalWrite(URTRIG, LOW);
  digitalWrite(URTRIG, HIGH);              

  unsigned long LowLevelTime = pulseIn(URECHO, LOW) ;
  if (LowLevelTime >= 50000)              // the reading is invalid.
  {
    Serial.println("Invalid");
    return 9999;
  }
  else
  {
    DistanceMeasured = LowLevelTime / 50;  // every 50us low level stands for 1cm
    return DistanceMeasured;
  }
 }
