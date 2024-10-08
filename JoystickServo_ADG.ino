

#include<Servo.h>
int x_pin = A0;  //X-axis pin
int y_pin = A1;
int sw_pin = 2;

int pos = 0;

Servo s1;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  s1.attach(3);          //Servo motor attached to pin 3
  s1.write(pos);

}

void loop()
{
 int x_data = analogRead(A0);
 int y_data = analogRead(A1);
 int sw_data = digitalRead(2);

 Serial.print("x_data:");
 Serial.print(x_data);
 Serial.print("\t");
 Serial.print("y_data:");
 Serial.print(y_data);
 Serial.print("\t");
 Serial.print("sw_data:");
 Serial.println(sw_data);
 delay(80);

if(x_data >= 550)
{
  if(pos <= 180)
  {
  pos = pos + 20;
  s1.write(pos);
  }
}
else if(x_data <= 500)
{
  if(pos >= 0)
  {
   pos = pos - 20;
   s1.write(pos);
  }
}
  
}
