/* 

RGB Common Anode LED Sketch Simulating A Police Emergency Light
 
 The circuit:
 * Red LED attached from pin 9 to +5V
 * Green LED attached from pin 10 to +5V
 * Blue LED attached from pin 11 to +5V

 
 Created: 2014 APR
 Author: Bryce Jones
 modified:
 
 This example code is in the public domain.
 
 Modified by LeRoy Miller Feb 20, 2015
 included a 2nd LEd
 */

// constants won't change. Used here to 
// set pin numbers:
const int rledPin =  9;      // the number of the RED LED pin
const int gledPin =  10;      // the number of the RED LED pin
const int bledPin =  11;      // the number of the RED LED pin
const int r1ledPin = 7;
const int g1ledPin = 6;
const int b1ledPin = 5;


// Variables will change:
int rledState = HIGH;            // ledState used to set the LED
int gledState = HIGH;            // ledState used to set the LED
int bledState = HIGH;  // ledState used to set the LED
int r1ledState = HIGH;
int g1ledState = HIGH;
int b1ledState = HIGH;
long previousMillis = 0;         // will store last time LED was updated

long interval = 100;             // interval at which to blink (milliseconds)
long fadeinterval=120;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by


void setup() {
  // set the digital(PWM) pin as output:
  pinMode(rledPin, OUTPUT);      
  pinMode(gledPin, OUTPUT);   
  pinMode(bledPin, OUTPUT);
  pinMode(r1ledPin, OUTPUT);
  pinMode(g1ledPin, OUTPUT);
  pinMode(b1ledPin, OUTPUT);
}

// Main Loop
void loop()  {
  for (int i=0; i<30; ++i){
  toggle();
  }
  dim();
}

void toggle(){
  // Method to flash LEDs in an alarming fashion
  //  toggling blue and red. Need to update to fade.

  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (rledState == LOW){
      rledState = HIGH;
      gledState = HIGH;
      bledState = LOW;
      r1ledState = LOW;
      g1ledState = HIGH;
      b1ledState = HIGH;
    }
    else {
      rledState = LOW;
      gledState = HIGH;
      bledState = HIGH;
      r1ledState = HIGH;
      g1ledState = HIGH;
      b1ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(rledPin, rledState);
    digitalWrite(gledPin, gledState);
    digitalWrite(bledPin, bledState);
    digitalWrite(r1ledPin, r1ledState);
    digitalWrite(g1ledPin, g1ledState);
    digitalWrite(b1ledPin, b1ledState);
    
  }
}
void dim() {
 // Method to flash LEDs in an alarming fashion
  //  toggling blue and red. Need to update to fade.

  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > fadeinterval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   


  // set the brightness of pin 9:
      rledState = HIGH;
      gledState = HIGH;
      bledState = HIGH;
      r1ledState = HIGH;
      g1ledState = HIGH;
      b1ledState = HIGH;
    analogWrite(rledPin, brightness);
    analogWrite(r1ledPin, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade: 
    if (brightness == 0 || brightness == 255) {
       fadeAmount = -fadeAmount ; 
    } 
    // wait for 30 milliseconds to see the dimming effect    
   //delay(30);
    }
}


