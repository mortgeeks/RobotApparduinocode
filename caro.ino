#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motorl(2);
AF_DCMotor motorr(4);

SoftwareSerial blSerial(0, 1);

char command;
String string;

void setup() {
  blSerial.begin(9600);
  
  motorl.setSpeed(200);
  motorr.setSpeed(200);
 
  motorl.run(RELEASE);
  motorr.run(RELEASE);
}

void loop() {
  
  if (blSerial.available() > 0) 
                          {string = "";}
    
    while(blSerial.available() > 0)
    {
      command = ((byte)blSerial.read());
      
      if(command == ':')
      {
        break;
      }    
      else
      {
        string += command;
      }
      delay(1);
    }
    if (string == "ON"){
      motorr.setSpeed(200);
    }
    if (string == "OFF"){
      motorl.setSpeed(0);
    }
    if(string == "UP")
    {
      motorr.run(FORWARD);
      motorl.run(FORWARD);
    }
    if(string == "DOWN")
    {
      motorr.run(BACKWARD);
      motorl.run(BACKWARD);
    }
    if(string == "RIGHT")
    {
       motorr.run(RELEASE);
       motorl.run(FORWARD);
         }
    if(string == "LEFT")
    {
       motorl.run(RELEASE);
       motorr.run(FORWARD);

    }
    if (string == "STOP"){
       motorr.run(RELEASE);
       motorl.run(RELEASE);
    }
    if ((string.toInt()>0)&&(string.toInt()<=255)){
      motorr.setSpeed(string.toInt());
      motorl.setSpeed(string.toInt());
    }


}
