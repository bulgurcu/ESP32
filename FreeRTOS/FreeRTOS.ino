void setup() {
  Serial.begin(112500);
 
  xTaskCreate(GorevBir,"GorevBir",10000,NULL,1,NULL); //GorevBir Task tanımı
  xTaskCreate(Goreviki,"Goreviki",10000,NULL,1,NULL); //Goreviki Task tanımı
  xTaskCreate(GorevUc,"GorevUc",10000,NULL,1,NULL); //Goreviki Task tanımı  
}
 
void loop() {
}
 
void GorevBir( void * parameter ){ //GorevBir komut satırı
    for( int i = 0;i<10;i++ ){
      Serial.println("Görev 1");
      delay(500);
    }
    Serial.println("Görev 1 Bitti");
    vTaskDelete( NULL );
}
 
void Goreviki( void * parameter){ //Goreviki komut satırı
    for( int i = 0;i<10;i++ ){
        Serial.println("Görev 2");
        delay(1000);
    }
    Serial.println("Görev 2 Bitti");
    vTaskDelete( NULL );
}

void GorevUc( void * parameter){ //GorevUc sonsuz görev komut satırı
  while(1){ // while komutu döngüyü sonsuza kadar sürdürüyor
    for( int i = 0;i<10;i++ ){
        Serial.println("Görev 3 ");
        delay(1000);
    }
    Serial.println("Görev 3 Bitti");
  }    
}
