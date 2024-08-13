
//Definimos los pines.
#define led1 14
#define led2 27
#define led3 26
#define led4 25
#define led5 33


// Definir leds. 
const int leds[5] = {led1, led2, led3, led4, led5};

// Definir leds para salida. 
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
// Ciclo for que va encendiendo cada led, y apagando el anterior de 0 -> 4.
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
    if (i - 1 >= 0) {
      digitalWrite(leds[i - 1], LOW);
    }
    delay(200);
  }
// Ciclo for que va encendiendo cada led, y apagando el anterior de 4 -> 0.
  for (int i = 4; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    if (i + 1 < 5) {
      digitalWrite(leds[i + 1], LOW);
    }
    delay(200);
  }
}
