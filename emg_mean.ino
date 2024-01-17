#include <Servo.h>

Servo myservo;
int media = 0;
int media_ult_100;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
pinMode(1, OUTPUT);
digitalWrite(1, LOW);
  // Inizializza la media a 0


  // Legge i primi 100 valori
  for (int i = 0; i < 100; i++) {
    media += analogRead(A1);
    delay(1);
  }

  // Divide la somma per il numero di valori letti
  media /= 100;
}

void loop() {
  
  for (int i = 0; i < 100; i++) {
    media_ult_100 += analogRead(A1);
    delay(1);
  }
  media_ult_100 /= 100;
  // Se il valore è maggiore della media, ruota il servo a 180 gradi
  if (media_ult_100 > media+ 20) {
    digitalWrite(13, HIGH);
    myservo.write(180);
  } else {
    // Altrimenti, ruota il servo a 0 gradi
    digitalWrite(13, LOW);
    myservo.write(0);
  }
  
  // Stampa il valore letto
  Serial.println("media:  " +String(media) + " , val: " +String(analogRead(A1)) + "   media_val: " +String(media_ult_100) );
  delay(100);
}
