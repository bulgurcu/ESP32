int buton = 14; //Pin tanımlaması

void setup(){
  pinMode(buton, INPUT_PULLUP); //buton setting tanımlama
    attachInterrupt(digitalPinToInterrupt(buton), butonToggle, CHANGE);
}

void butonToggle(){
  //Interrupt aktif olunca çalışacak kod bölümü
}
