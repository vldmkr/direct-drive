#include <TaskScheduler.h>
#include "DirectStepper.h"

DirectStepper mStepper(7,6,5,4);
Scheduler mScheduler;

Counter mStepperCounter;

Task t1(0, -1, &t1Callback);
Task t2(5100, -1, &t2Callback);

void setup(){
  Serial.begin(9600);
  mStepper.setForward(false);
  pinMode(13, OUTPUT);
  t1.enable(); 
  t2.enable();
  mScheduler.init();
  mScheduler.addTask(t1);
  mScheduler.addTask(t2);
}

void loop(){
  mScheduler.execute();
}


void t1Callback() {
  if(mStepperCounter.next()){
    mStepper.nextStep();
    delay(1); 
  }
}
boolean a = false;
void t2Callback() {
  digitalWrite(13, a=!a);
  mStepper.setForward(a);
  mStepperCounter.setCounts(4076);
}