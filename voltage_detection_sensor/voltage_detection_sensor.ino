//Voltage Detection module code
//http://www.ebay.com/itm/161758492882?_trksid=p2060353.m2749.l2649&ssPageName=STRK%3AMEBIDX%3AIT


#include <Wire.h>
int LED1 = 13;
int val11;
int val2;

void setup()
{
pinMode(LED1,OUTPUT);
Serial.begin(9600);
Serial.println("Emartee.Com");
Serial.println("Voltage: ");
Serial.print("V");
}
void loop()
{
float temp;
val11=analogRead(1);
temp=val11/4.092;
val11=(int)temp;//
val2=((val11%100)/10);
Serial.println(val2);
delay(1000);
}
