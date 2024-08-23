

// En 10 milisegundos se deja de ver, el parpadeo. 

#define led1 14
#define led2 27
#define led3 26
#define led4 25
#define led5 33

const int mili = 10;
const int leds[5] = {led1, led2, led3, led4, led5};

void setup() {
  //Defino mis pines como salida dentro de un ciclo for
  for (int i = 0; i < 5 ; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(mili);

  for (int i = 4; i >= 0; i--) {
    digitalWrite(leds[i], LOW);
  }
  delay(mili);
}
