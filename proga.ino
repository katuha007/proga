#include <AFMotor.h>
#include <Servo.h>
int val;
Servo serv;
AF_DCMotor motor1(2); 
AF_DCMotor motor2(4);
void setup()
{ serv.attach(9); 
  Serial.begin(9600);
  
  
}
void loop()
{
  if (Serial.available())
  {
    val = Serial.read() - '0' ;
    if (val == 1)
    {
  motor1.run(BACKWARD);  
  motor2.run(BACKWARD);  
  motor1.setSpeed(255);   
  motor2.setSpeed(255); 
    }
    if ( val == 0 )
    {
  motor1.setSpeed(0);   
  motor2.setSpeed(0); 
    }
   if (val == 2) {
  motor1.run(FORWARD);  
  motor2.run(BACKWARD);  
  motor1.setSpeed(200);   
  motor2.setSpeed(200);
  
  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
   }
   if (val == 3){
  motor1.run(BACKWARD);  
  motor2.run(FORWARD);  
  motor1.setSpeed(200);   
  motor2.setSpeed(200);
   }
   if (val == 4){
  motor1.run(FORWARD);  
  motor2.run(FORWARD);  
  motor1.setSpeed(255);   
  motor2.setSpeed(255);
  
   } if (val == 5) {
     for(int i = 0; i <= 180; i++)        
  {
    serv.write(i);
  }                        
  }
  if (val == 6){
    for (int i = 0; i>= -180; i--){
      serv.write(i);
    }
  }
  if (val == 7){
      pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
   
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  }
  if (val == 8){
      pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(13 ,LOW);
  }
  
  }
  }
