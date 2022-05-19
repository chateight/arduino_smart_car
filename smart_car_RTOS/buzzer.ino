int pinNo = 16;
void buzzer_setup() {
  tone( pinNo, 98, 200 );   // Gの音を発信
  delay( 220 );
  tone( pinNo, 110, 200 );  // Aの音を発信
  delay( 220 );
  tone( pinNo, 123, 200 );  // Bの音を発信
  delay( 220 );
  tone( pinNo, 130, 200 );  // Cの音を発信
  delay( 1000 );
}

void back_sound() {
  //tone( pinNo, 98, 100 );  // Gの音を発信
  //delay( 150 );
  //tone( pinNo, 98, 100 );  // Gの音を発信
  //delay( 150 );

  for(uint16_t count=0; count<78; count++){
    digitalWrite(pinNo, HIGH);
    delayMicroseconds(1908);
    digitalWrite(pinNo, LOW);
    delayMicroseconds(1909);
  }
}
