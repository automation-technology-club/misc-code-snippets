#include <Arduino.h>

#include <SoftwareSerial.h>

#include <PID_v1.h>





#define M1A 2

#define M1B 3

#define M2A 4

#define M2B 5





int deltaTime = 50;

double setPoint = 10;

double input, output;

int lastCount = 0;

volatile unsigned int counter = 0;





PID pid(&input, &output, &setPoint, 20, 0, 0, DIRECT);

SoftwareSerial s(16, 15);





void countInt() {

    counter++;

}





void motor(byte which, byte spd, byte dir){

  byte a = M1A;

  byte b = M1B;

  if (which == 1){

	a = M2A;

	b = M2B;

  }



  if (dir == 1){

	digitalWrite(a, HIGH);

	analogWrite(b, 255-spd);

  }

  else{

	digitalWrite(a, LOW);

	analogWrite(b, spd);

  }

}





void setup() {

    pinMode(M1A, OUTPUT);

    pinMode(M1B, OUTPUT);

    pinMode(M2A, OUTPUT);

    pinMode(M2B, OUTPUT);



    pid.SetMode(AUTOMATIC);

    pid.SetOutputLimits(0, 255);

    pid.SetSampleTime(deltaTime);



    s.begin(9600);



	// Kooder - loeme, kui palju mootori võll liigub

    pinMode(0, INPUT_PULLUP);

    attachInterrupt(2, countInt, CHANGE);

    interrupts();

}





void loop() {

    if (s.available()) {



        float kp = s.parseFloat();

        float ki = s.parseFloat();

        float kd = s.parseFloat();



        pid.SetTunings(kp, ki, kd);



        while(s.available()>0) {

            s.read();

        }

    }

    

    delay(deltaTime);



    input = counter-lastCount;

    lastCount = counter;

    

    pid.Compute();

    motor(0, output, 0);

}


