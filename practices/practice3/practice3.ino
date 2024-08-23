// Definimos pines. 
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

  Serial.begin(115200);
}

void loop() {
  int in_up = digitalRead(btnUp);
  int in_down = digitalRead(btnDown);
  
  if (in_up == LOW) {
    if (millis() > timeCounter + timeThreshold) {
      if (idx > 4) {
        LedsOff();
        idx = 0;
      } else {
        digitalWrite(leds[idx], HIGH);
        idx++;
        Serial.println(idx);
      }
      timeCounter = millis();
    }
  }

  if (in_down == HIGH) {
    if (millis() > timeCounter + timeThreshold) {
      LedsOff();
      idx = 0;
      timeCounter = millis();
    }
  }
  
  

}
