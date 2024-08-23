// Definimos pines de los botones y leds.  
#define btnUp 4 // btn 1.
#define btnDown 15 // btn 2.

#define led1 14
#define led2 27
#define led3 26
#define led4 25
#define led5 33

const int leds[5] = {led1, led2, led3, led4, led5};

long timeCounter = 0;
const int timeThreshold = 200;
int idx = 0;

void LedsOff() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);  
  }
}

void setup() {
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);  
  }
}

void loop() { 
  // Leer si los botones son presionados. 
  int in_up = digitalRead(btnUp);
  int in_down = digitalRead(btnDown);
  
  if (in_up == LOW) { 
    if (millis() > timeCounter + timeThreshold) {
      if (idx > 4) { // Si es el ultimo led reiniciamos el index y apagamos todos los leds. 
        LedsOff();
        idx = 0;
      } else { // Si no encendemos el siguiente led. 
        digitalWrite(leds[idx], HIGH);
        idx++;
      }
      timeCounter = millis();
    }
  }

  if (in_down == HIGH) {
    if (millis() > timeCounter + timeThreshold) { // Si apretamos el segundo boton apagamos todos los leds. 
      LedsOff();
      idx = 0;
      timeCounter = millis();
    }
  }
  
  

}
