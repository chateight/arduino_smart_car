//ライブラリインクルード
#include <Stepper.h>

// ステッピングモータが1回転するのに必要なステップ数を定義
//2相励磁方式で制御するため2048 step で1回転
const int MOTOR_STEPS = 2048; 

//1回転あたりのステップ数と接続するピンの設定
Stepper myStepper(MOTOR_STEPS, 8, 10, 9, 13);
 
void init_s_motor() { 
  myStepper.setSpeed(10); // 10回転/1分に設定 rpm（1分あたりの回転数）
  digitalWrite(8,  LOW); 
  digitalWrite(9,  LOW); 
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW); 
  }
  
void s_motor() { 
  myStepper.step(-128);    // 512ステップで90度回転
  myDelayMs(300);
  myStepper.step(256);    
  //myDelayMs(300);
  //myStepper.step(128);    
  //myDelayMs(300);
  //myStepper.step(-128);    
  
  // 静止時には電流を遮断する。 
  digitalWrite(8,  LOW); 
  digitalWrite(9,  LOW); 
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW); 
  //
}
