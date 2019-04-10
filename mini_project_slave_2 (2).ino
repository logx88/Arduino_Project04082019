#include <LiquidCrystal.h>
//#include <Wire.h>
//LiquidCrystal lcd(4,3,2,1,0,A1,A2);
int pin_ROW[4] = {13, 12, 11, 10};
int pin_COLUMN[4] = {9, 8, 7, 6};
int pin_BUZZER=A0;
int pin_GND=5;
//volatile int pin_GND = 5;
int Pitch_data[16]={261,293,329,349,391,440,493,523,587,659,698,783,880,987,1046,2093};
void setup() {
  // put your setup code here, to run once:
//  Wire.begin(8);
//  Wire.onReceive(receiveEvent);
//  Serial.begin(9600);

  //while(1){
//  lcd.begin(16,2);
//  lcd.print("SW1:song(1)");
//  lcd.setCursor(0,1);
//  lcd.print("SW2:song(2)");
//  delay(2000);
//  lcd.clear();
//  lcd.print("SW3:exit");
//  lcd.setCursor(0,1);
//  lcd.print("SW4:Pause");
  //}

  for(int i=0;i<4;i++)
  {
    pinMode(pin_ROW[i],OUTPUT);
    pinMode(pin_COLUMN[i],INPUT);
  }
  pinMode(pin_GND, OUTPUT);
  digitalWrite(pin_GND, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:

int i, j;
int ROW, COLUMN, Number;
for(i=0; i<4; i++)
{
digitalWrite(pin_ROW[i], HIGH);
ROW = 0;
ROW = i*4; // ROW = 0, 4, 8, 12
for(j=0; j<4; j++)
{
COLUMN = 0;
COLUMN += j; // COLUMN = 0, 1, 2, 3
if(digitalRead(pin_COLUMN[j]))
{
Number = ROW + COLUMN;
Serial.print("KEY [");
Serial.print(Number, HEX);
 Serial.println("] PUSH");
 tone(pin_BUZZER,Pitch_data[Number]);
                            delay(300);
                            noTone(pin_BUZZER);
}
}
digitalWrite(pin_ROW[i], LOW);
//delay(100);
}
}

//void receiveEvent(int select)
//{
////  lcd.clear();
//  int data=Wire.read();
//
//  Serial.println("test");
//  delay(1000);
//  
//  if(data==1){
////  lcd.clear();
////  lcd.print("You are listeni");
////  lcd.setCursor(0,1);
////  lcd.print("ng Happy House");
//  Serial.println(data);
//  delay(1000);
//  }
//  
//  if(data==2){
////  lcd.clear();
////  lcd.print("School Song");
//  Serial.println(data);
//  delay(1000);
//  }
//}
