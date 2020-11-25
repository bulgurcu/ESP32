void setup() {
  Serial.begin(112500);
 
  xTaskCreate(GorevBir,"GorevBir",10000,NULL,1,NULL); //GorevBir Task tanımı
  xTaskCreate(Goreviki,"Goreviki",10000,NULL,1,NULL); //Goreviki Task tanımı
}
 
void loop() {
}
 
void GorevBir( void * parameter ){ //GorevBir komut satırı
    for( int i = 0;i<10;i++ ){
      Serial.println("Hello from task 1");
      delay(500);
    }
    Serial.println("Ending task 1");
    vTaskDelete( NULL );
}
 
void Goreviki( void * parameter){ //Goreviki komut satırı
    for( int i = 0;i<10;i++ ){
        Serial.println("Hello from task 2");
        delay(1000);
    }
    Serial.println("Ending task 2");
    vTaskDelete( NULL );
}
