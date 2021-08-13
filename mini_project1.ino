/*
	Ezz Abu Asab 1160730

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float finalValue;
int tempr=A1;

void setup() {
  
  pinMode(tempr,INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  
  	lcd.setCursor(0,0);
	lcd.print("Mini Project :) ");
  	finalValue= getTemp(tempr);
  	finalValue= (finalValue - 0.5) * 100;
  	//converts to degrees Celcius
  
   	// set the cursor to column 1, line 1
  	// (note: line 1 is the second row, since counting begins with 0):
  	lcd.setCursor(0,1);
	lcd.print("Tmp:");
  	lcd.print(finalValue);	// print temperature
  	delay(1000);
  	lcd.clear();
}

float getTemp(int pin)
{
  	// 5V/1024 = 0.004882814V  = Voltage increase per step
	return (analogRead(pin) * .004882814); 
  	//Calculates temperature based on voltage of 5V, divided from 0 to 1023
}
 