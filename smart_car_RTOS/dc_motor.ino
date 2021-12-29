// デジタルピンの定義(global variables)
// pin number start from 0(D0)
 const int IN1 = 1;
 const int IN2 = 2;
 const int IN3 = 3;
 const int IN4 = 4;
 const int ENA = 0;  // PWM制御で使うENAピンをD9に(モーター1のPWM制御ピン)
 const int ENB = 5;  // PWM制御で使うENBピンをD10に(モーター2のPWM制御ピン)
 
 //int i = 0;
 //int step = 5;

 
void init_dc_motor(){ 
   pinMode(IN1, OUTPUT);  // デジタルピンを出力に設定
   pinMode(IN2, OUTPUT);
   pinMode(IN3, OUTPUT);
   pinMode(IN4, OUTPUT);
   pinMode(ENA, OUTPUT);
   pinMode(ENB, OUTPUT);
}

void dc_motor(int g){
   long randNumber;
// g=0 : forward, 1 : backword, others : stop
switch (g){
  case 0:
//  if (g==0){
   digitalWrite(IN1, HIGH); // HIGH LOWの組み合わせでモーター回転
   digitalWrite(IN2, LOW);  // 2つのモーターを正回転
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   analogWrite(ENA, 170);
   analogWrite(ENB, 170);
   break;
//
  case 1:
   randNumber = random(2);  // 0と1の乱数を生成
   digitalWrite(IN1, LOW);  // HIGH LOWの組み合わせでモーター回転
   digitalWrite(IN2, HIGH); // 2つのモーターを逆回転(上記とは反対に回転)
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   if (randNumber==0){
   analogWrite(ENA, 160);
   analogWrite(ENB, 255);
    }
   else{
    analogWrite(ENA, 255);
    analogWrite(ENB, 160);
   }
   myDelayMs(500);
   digitalWrite(IN1, LOW);  // stopping the motors
   digitalWrite(IN2, LOW);  // 
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   break;
//
  case 2:
   digitalWrite(IN1, LOW);  // stopping the motors
   digitalWrite(IN2, LOW);  // 
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
  }
}
