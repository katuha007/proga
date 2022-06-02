#include <AFMotor.h>
#include <Servo.h>
int val;
int y1 = 0;
int y2 = 0;
int last = 0;
Servo servl;
Servo servp;
AF_DCMotor motor1(2);
AF_DCMotor motor2(4);
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT); // СТРЕЛЬБА
  pinMode(7,OUTPUT); // при перезарядке
  pinMode(5,OUTPUT);// при движении
  servl.attach(10);
  servp.attach(9);
  Serial.begin(9600);
  digitalWrite(12, 0);
  digitalWrite(13 , 0);
  digitalWrite(7, 0);
  digitalWrite(5, 0);
   digitalWrite(8, 0);
}
void loop()
{
  if ( Serial.available() )
  {
    val = Serial.read() - '0' ;
    if (val == 1)
    {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      digitalWrite(12, 0);
      digitalWrite(13 , 0);
     digitalWrite(7, 0);
  digitalWrite(5 , 1);
   digitalWrite(8, 0);
      
    }
    if ( val == 0 )
    {
      motor1.setSpeed(0);
      motor2.setSpeed(0);
      digitalWrite(12, 0);
      digitalWrite(13 , 0);
    digitalWrite(7, 0);
  digitalWrite(5 , 0);
   digitalWrite(8 , 0);
    }
    if (val == 2) {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor1.setSpeed(250);
      motor2.setSpeed(250);
      digitalWrite(12, 0);
      digitalWrite(13 , 0);
        digitalWrite(7, 0);
  digitalWrite(5, 1);
   digitalWrite(8, 0);
    }
    if (val == 3) {
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor1.setSpeed(250);
      motor2.setSpeed(250);
      digitalWrite(12, 0);
      digitalWrite(13 , 0);
        digitalWrite(7, 0);
  digitalWrite(5, 1);
   digitalWrite(8, 0);
    }
    if (val == 4) {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor1.setSpeed(255);
      motor2.setSpeed(255);
      digitalWrite(12, 0);
      digitalWrite(13 , 0);
        digitalWrite(7, 0);
  digitalWrite(5 , 1);
   digitalWrite(8, 0);
    }
    if (val == 5)
    {
      if ( y1 <= 175 )
        y1 += 1;
      servl.write(y1);
    }
    if (val == 6)
    {
      if ( y1 >= 5 )
        y1 -= 1;
      servl.write(y1);
    }
    if (val == 7)
    {
      if ( y2 <= 175 )
        y2 += 1;
      servp.write(y2);
    }
    if (val == 8)
    {
      if ( y2 >= 5 )
        y2 -= 1;
      servp.write(y2);
    }
    if (val == 9)
    {
      if ( last ) {
        digitalWrite(12, 0);
        digitalWrite(13 , 0);
          digitalWrite(7, 0);
  digitalWrite(5 , 0);
    digitalWrite(8,0);
        last = 0;
      }
      else
      { digitalWrite(8,0);
      digitalWrite(12, 1);
      delay(30);
       digitalWrite(7,1);
       delay(30);
        digitalWrite(13 , 1);
        delay(300);
        digitalWrite(12 , 0);
             digitalWrite(7,0);
             digitalWrite(13,0);
          digitalWrite(8, 1);
          delay(3000);
           digitalWrite(5,0);
           digitalWrite(8,0);
  
        last = 1;
      }
    }
  }
}
