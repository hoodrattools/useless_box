#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


#define relay 8 
#define button_pin 7
#define sda 2
#define slc 3

Servo lid;  // create servo object to control a servo
Servo finger;
LiquidCrystal_I2C lcd(0x27,20,4);
void words(void);
void words1(void);
void words2(void);

int zero = 10;  
int lid_open = 75;
int button_press = 75;
int button;
int counter=0;


void setup() {
  lid.attach(9);  
  finger.attach(10);
  pinMode(relay, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  lid.write(zero);
  finger.write(zero);
  Serial.begin(9600);
  digitalWrite(relay, LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

  
}


void loop() 
{
  button = digitalRead(button_pin);
  Serial.println(button);
  if (button==0)
  {
    digitalWrite(relay, HIGH);
    if (counter==0)
    {
      words();
    }
    if (counter==1)
    {
      words1();
    }
    if (counter==2)
    {
      words2();
    }
    Serial.println("lid open");
    finger.write(button_press);
    button = digitalRead(button_pin);
    Serial.println(button);
    while (button==0)
    {
    delay(200);
    finger.write(zero);
    delay(200);
    finger.write(button_press);
    button = digitalRead(button_pin);
    }
    digitalWrite(relay, LOW);
    delay(1000);
    finger.write(zero);
    delay(500);
    lid.write(zero);
    Serial.println("lid closed");  
    counter = counter+1;
    if (counter==3) 
    {
        counter = 0;
    }
  }
  
}

void words()
{
    Serial.println(button);
    lcd.setCursor(5,0);
    lcd.print("Leave");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("  Me ");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Alone >:(");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("            ");
    lid.write(lid_open);
    delay(500);
}

void words1()
{
    Serial.println(button);
    lcd.setCursor(5,0);
    lcd.print("This");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("  Is");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Harrassment!");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("            ");
    lid.write(lid_open);
    delay(500);
}


void words2()
{
    Serial.println(button);
    lcd.setCursor(5,0);
    lcd.print("Let ");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print(" Me       ");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("Die :,(");
    delay(500);
    lcd.setCursor(5,0);
    lcd.print("            ");
    lid.write(lid_open);
    delay(500);
}



          
    
