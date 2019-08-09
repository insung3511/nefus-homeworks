#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int a, count = 0;
int button10 = 0;                           //plus 10 button int
int button1  = 0;                           //plus 1 button int
int result   = 0;

void setup() {
  pinMode(INPUT, 9); //Plus 10 Button
  pinMode(INPUT, 8); //Plus  1 Button
  pinMode(OUTPUT, 13);
  //Rotation Sensor == Result 
  lcd.begin();
  lcd.clear();
  lcd.backlight();

  Serial.begin(9600);           
  randomSeed(analogRead(1));  //Make Random Number
}

void game() {
  count = 0;
  int randNum = random(1,20);
  int getRotateState = analogRead(A0);      //Final Plus Rotation Sensor state (0 ~ 1023)

  while(1) {
    Button();
    if(a == randNum) {
      break;
    }
    
      if (a == 0){ 
          ;  
      }

      else if (a < randNum) {
        count++;
        lcd.clear();
        lcd.print(a);
        lcd.print(" : " );
        lcd.print("UP!!");
        delay(1500);
        button1, button10 = 0;        
        a = 0;
        continue;

      }
      
      else if (a > randNum) {
        count++;
        lcd.clear();
        lcd.print(a);
        lcd.print(" : " );
        lcd.print("Down!!");
        delay(1500);
        button1, button10 = 0;
        a = 0;
        continue;
      }     
  }
}


int Button() {
  int getButtonState_Plus10 = digitalRead(9);     //plus 10 button get state (HIGH or LOW)
  int getButtonState_Plus1  = digitalRead(8);     //plus  1 button get state (HIGH or LOW)
  int getRotateState        = analogRead(A0);      //Final Plus Rotation Sensor state (0 ~ 1023)

  // Button +1
  if (getButtonState_Plus1 == HIGH) {
    lcd.clear();
    button1++;

    result = button1;        //Result
    lcd.print("Number = ");             
    lcd.print(result);
    delay(350);

    if (button1 >= 20) {                //1+ button over 10 => set button1 0
      button1 = 0;
    }
  }

  //Button +10
  if (getButtonState_Plus10 == HIGH) {
    lcd.clear();
    button1--;

    result = button1;        //Result
    lcd.print("Number = ");
    lcd.print(result);
    delay(350);

    if (button1 <= 0) {               ////10+ button over 100 => set button10 0
      button1 = 0; 
    }
  }

  //Final Result
  if (getRotateState >= 1020) {
     button1, button10 = 0;
     a = result;
  }
}

void loop() {
  lcd.print("S"); delay(100);
  lcd.print("T"); delay(100);
  lcd.print("A"); delay(100);
  lcd.print("R"); delay(100);
  lcd.print("T"); delay(100);
  
  game();
  lcd.clear();
  lcd.print(a);
  lcd.print(" : ");
  lcd.print("Good!");
  delay(2000);  lcd.clear();

  //LCD Print Wrong Count
  lcd.print("Miss Count : ");
  lcd.print(count);
  delay(2000);  lcd.clear();

  lcd.print("If play Again");
  delay(1500);  lcd.clear();
  lcd.print("Turn it on/off");
  delay(1500000000000000);  lcd.clear();
}