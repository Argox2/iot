
// 5 leds > 4166
// 4 leds > 3333
// 3 leds > 2500
// 2 leds > 1666
// 1 leds > 833
// 0 leds > 

// 5000 / 6


#define LDR 34

#define led1 14
#define led2 27
#define led3 26
#define led4 25
#define led5 33

const int leds[5] = {led1, led2, led3, led4, led5};

int maxSensor = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(LDR, INPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);  
  }
}

void OnLeds(int idx) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);  
  }

  
  for (int i = 0; i < idx; i++) {
    digitalWrite(leds[i], HIGH);  
  }
}

void loop() {
  int sensor = analogRead(LDR);
  float divMaxSensor = maxSensor/6;
  
  if (sensor > divMaxSensor*5) {
    OnLeds(0);
  } else if (sensor > divMaxSensor*4) {
    OnLeds(1);
  } else if (sensor > divMaxSensor*3) {
    OnLeds(2);
  } else if (sensor > divMaxSensor*2) {
    OnLeds(3);
  } else if (sensor > divMaxSensor*1) {
    OnLeds(4);
  } else {
    OnLeds(5);
    } 
}
