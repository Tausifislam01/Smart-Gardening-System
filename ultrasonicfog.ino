
byte TP = 0b10101010; //her 2. bağlantı noktası ters sinyali alır

void setup()
{
 DDRC = 0b11111111; //By Zafer YILDIZ
 
  // Zamanlayıcı 1'i başlat
  noInterrupts();           
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 205;              
  TCCR1B |= (1 << WGM12);   
  TCCR1B |= (1 << CS10);   
  TIMSK1 |= (1 << OCIE1A); 
  interrupts();             
}

ISR(TIMER1_COMPA_vect)          
{
  PORTC = TP; // TP değerini çıktılara gönder
  TP = ~TP;   // TP sonraki çalıştırma için ters çevir
}

void loop(){
  // By Zafer YILDIZ
}
