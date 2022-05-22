//ライブラリインクルード
#include <Stepper.h>

// ステッピングモータが1回転するのに必要なステップ数を定義
// 1-22相励磁方式で制御するため2048 step で1回転
const int MOTOR_STEPS = 2048; 

const int IN1_sm = 8;
const int IN2_sm = 9;
const int IN3_sm = 10;
const int IN4_sm = 13;

const int d_hs[8] = {
  0B00001000, 
  0B00001100,
  0B00000100,
  0B00000110,
  0B00000010,
  0B00000011,
  0B00000001,
  0B00001001
};

int i_step = 0;

//1回転あたりのステップ数と接続するピンの設定
Stepper myStepper(MOTOR_STEPS, 8, 10, 9, 13);
 
void init_s_motor() { 
  myStepper.setSpeed(5); // 5回転/1分に設定 rpm（1分あたりの回転数）
  pinMode(IN1_sm, OUTPUT);
  pinMode(IN2_sm, OUTPUT);
  pinMode(IN3_sm, OUTPUT);
  pinMode(IN4_sm, OUTPUT);
  digitalWrite(8,  LOW); 
  digitalWrite(9,  LOW); 
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW); 
  }
  
void s_motor() { 
  myStepper.step(256);     // 1024ステップで90度回転
  myDelayMs(300);
  myStepper.step(-256);
  myDelayMs(300);
  myStepper.step(-256);
  myDelayMs(300);
  myStepper.step(256);    
  myDelayMs(300);
  
  // 静止時には電流を遮断する。 
  digitalWrite(8,  LOW); 
  digitalWrite(9,  LOW); 
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW); 
  //
}

void s_motor_()
{
  for(int i=0; i < 256; ++i)
  { 
    step(1);
    delayMicroseconds(3000);
  }
  for(int i=0; i < 512; ++i)
  {
    step(-1);
    delayMicroseconds(3000);
  }
  for(int i=0; i < 256; ++i)
  { 
    step(1);
    delayMicroseconds(3000);
  }
  // 静止時には電流を遮断する。 
  digitalWrite(8,  LOW); 
  digitalWrite(9,  LOW); 
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW); 
}

void step(int d)  // d = -1 : anticlockwise, d = 1 : clockwise
{
  i_step += d;
  if(i_step > 7) i_step = 0;
  if(i_step < 0) i_step = 7;
  byte b = d_hs[i_step];
  digitalWrite(IN1, bitRead(b, 0));
  digitalWrite(IN2, bitRead(b, 1));
  digitalWrite(IN3, bitRead(b, 2));
  digitalWrite(IN4, bitRead(b, 3));
}
