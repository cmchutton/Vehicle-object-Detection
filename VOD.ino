




// include the library code:
#include <LiquidCrystal.h>

int inches = 0;
const int buzzer = 9;
int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  Serial.begin(9600);
 
} 
void loop() {

  // measure the ping time, multiply by speed of sound in cm per microsecond / 2 for travel and return
  cm =  readUltrasonicDistance(3, 2)*  0.034/2;  
  
 // measure the ping time, multiply by speed of sound in inches per microsecond / 2 travel time and return time
  inches = readUltrasonicDistance(3, 2) * 0.0135/2; 
 
  
  //if nothing is in the sensor's range it will continuously display 132 inches which is past its range
  
  if(inches <=131 ){
     lcd.setCursor(0,0);
     lcd.print("Distance: ");
     lcd.print(inches);
     lcd.print("in");
     delay(30);
     lcd.setCursor(0,1);
     lcd.print("Distance: ");
     lcd.print(cm);
     lcd.print("cm");
     delay(30);
   
   
   
  }
  else{
   lcd.clear();
   lcd.home();  
   lcd.print("clear");
   

   
  }  
    

    
     
  }
