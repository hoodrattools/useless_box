#include <Servo.h>
#define relay 8 
#define button_pin 7

Servo lid;  // create servo object to control a servo
Servo finger;

int zero = 10;  
int lid_open = 75;
int button_press = 75;
int button;


void setup() {
  lid.attach(9);  
  finger.attach(10);
  pinMode(relay, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  lid.write(zero);
  finger.write(zero);
  Serial.begin(9600);
  digitalWrite(relay, LOW);
}


void loop() 
{
  button = digitalRead(button_pin);
  Serial.println(button);
  if (button==0)
  {
    Serial.println(button);
    digitalWrite(relay, HIGH);
    lid.write(lid_open);
    delay(500);
    Serial.println("lid open");
    finger.write(button_press);
    digitalWrite(relay, LOW);
    delay(1000);
    finger.write(zero);
    delay(500);
    lid.write(zero);
    Serial.println("lid closed");    
  }
  
}



          
    
