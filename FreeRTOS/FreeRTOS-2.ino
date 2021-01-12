#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

TaskHandle_t HandGorevbir;
TaskHandle_t HandGoreviki;
TaskHandle_t HandGorevuc;
TaskHandle_t HandGorevdort;

void Gorevbir( void *pvParameters );
void Goreviki( void *pvParameters );
void Gorevuc( void *pvParameters );
void Gorevdort( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.print("Setup CORE:");
  Serial.println(xPortGetCoreID());
  
  
  // Now set tasks to run independently.
  xTaskCreatePinnedToCore(Gorevbir    ,"Gorevbir"   ,1024,NULL,2,&HandGorevbir   ,ARDUINO_RUNNING_CORE);
      Serial.println("Gorevbir START");
  xTaskCreatePinnedToCore(Goreviki    ,"Goreviki"   ,1024,NULL,2,&HandGoreviki   ,ARDUINO_RUNNING_CORE);
    Serial.println("Goreviki START");  
  xTaskCreatePinnedToCore(Gorevuc     ,"Gorevuc"    ,1024,NULL,2,&HandGorevuc    ,0);
    Serial.println("Gorevuc START");  
  xTaskCreatePinnedToCore(Gorevdort   ,"Gorevdort"  ,1024,NULL,2,&HandGorevdort  ,1);  
    Serial.println("Gorevdort START");
}

void loop() {
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void Gorevbir(void *pvParameters) {
  (void) pvParameters;
    UBaseType_t uxHighWaterMark;
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("Gorevbir Stack:"); Serial.println(uxHighWaterMark);
    vTaskSuspend(HandGorevbir);
  for (;;) {
    Serial.println("Gorevbir");
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print(":"); Serial.print(uxHighWaterMark); Serial.print("-"); Serial.println(xPortGetCoreID());    
    vTaskDelay(500);    
  }
}

void Goreviki(void *pvParameters) {
  (void) pvParameters;
    UBaseType_t uxHighWaterMark;
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("Gorevbir Stack:"); Serial.println(uxHighWaterMark);  
  for (;;) {
    Serial.println("          Goreviki");
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("          :"); Serial.print(uxHighWaterMark); Serial.print("-"); Serial.println(xPortGetCoreID());
    vTaskDelay(1000);
  }
}

void Gorevuc(void *pvParameters) {
  (void) pvParameters;
    UBaseType_t uxHighWaterMark;
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("Gorevbir Stack:"); Serial.println(uxHighWaterMark);  
  for (;;) {
    Serial.println("                    Goreviuc");
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("                    :"); Serial.print(uxHighWaterMark); Serial.print("-"); Serial.println(xPortGetCoreID());
    vTaskDelay(2000);
  }
}

void Gorevdort(void *pvParameters) {
  (void) pvParameters;
    UBaseType_t uxHighWaterMark;
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("Gorevbir Stack:"); Serial.println(uxHighWaterMark);  
  for (;;) {
    Serial.println("                              Gorevdort");
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("                              :"); Serial.print(uxHighWaterMark); Serial.print("-"); Serial.println(xPortGetCoreID());
    vTaskResume(HandGorevbir);
    vTaskDelay(1000);
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("                              :"); Serial.print(uxHighWaterMark); Serial.print("-"); Serial.println(xPortGetCoreID());
    vTaskSuspend(HandGorevbir);
    vTaskDelay(3000);
  }
}

/************************************************* ÖRNEK ŞABLON
void Gorevdort(void *pvParameters) {
  (void) pvParameters;
    UBaseType_t uxHighWaterMark;
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
    Serial.print("Gorevdort Stack:"); Serial.print(uxHighWaterMark); Serial.print("-"); Serial.println(xPortGetCoreID());
  for (;;) {
    Serial.println("                              Gorevdort");
    vTaskDelay(4000);
  }
}
*/
