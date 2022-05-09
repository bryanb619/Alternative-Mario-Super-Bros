// Digital pins
const int trigger1 = 9;
const int echo1 = 10;
const int trigger2 =  5;
const int echo2 = 6;
const int trigger3 =  2;
const int echo3 = 3;
const int shoot =  12;

const int pressed_distance = 15;
const int pressed_distance_jump_offset = 2;

int jump;
int leftButton;
int RightButton;

#include "SRF05.h"
SRF05 SRF1(trigger1, echo1);
SRF05 SRF2(trigger2, echo2);
SRF05 SRF3(trigger3, echo3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(shoot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(SRF.getCentimeter(), 1);
  //delay(100);
  CheckDistance();

  //jump button
  if(CheckIfPressedJump(jump)){
    Serial.println("x");
  }else{
    Serial.println("!x");
  }
  //left button
  if(CheckIfPressed(leftButton)){
    Serial.println("a");
  }else{
    Serial.println("!a");
  }
  //right button
  if(CheckIfPressed(RightButton)){
    Serial.println("d");
  }else{
    Serial.println("!d");
  }
  //shoot button
  if(digitalRead(shoot) == HIGH){
    Serial.println("z");
  }else{
    Serial.println("!z");
  }
}


//check the distance in each sensor
void CheckDistance(){
  jump = SRF1.getCentimeter();
  leftButton = SRF2.getCentimeter();
  RightButton = SRF3.getCentimeter();
}

bool CheckIfPressedJump(int x){
  bool buttonValue = false;
  
  if(x<pressed_distance - pressed_distance_jump_offset){
    buttonValue = false;  
  }else if(x>pressed_distance + pressed_distance_jump_offset){
     buttonValue = true;
  }

  return buttonValue;
}

bool CheckIfPressed(int x){
  bool buttonValue = false;
  
  if(x<pressed_distance){
    buttonValue = true;  
  }

  return buttonValue;
}
