//attachInterrupt(digitalPinToInterrupt(A), B, C);
  //A = Input Tanımı
  //B = Kesme meydana gelince çalışacak olan komut dizisi
  //C = Kesmenin meydana geleceği koşul

//LOW = Düşük olduğunda
//HIGH = Yüksek olduğunda
//CHANGE = Durum her değiştiğinde kesmeyi tetiklemek için. Örneğin, HIGH'dan LOW'a veya LOW'dan HIGH'a gittiğinde
//FALLING = HIGH'dan LOW'a geçtiğinde.
//RISING = LOW'dan HIGH'a geçtiğinde tetiklemek için


int buton = 14; //Pin tanımlaması

void setup(){
  pinMode(buton, INPUT_PULLUP); //buton setting tanımlama
    attachInterrupt(digitalPinToInterrupt(buton), butonToggle, CHANGE);
}

void butonToggle(){
  //Interrupt aktif olunca çalışacak kod bölümü
}
