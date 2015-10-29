#include "DirectStepper.h"

DirectStepper::DirectStepper(byte pin1, byte pin2, byte pin3, byte pin4)
: mPin1(pin1), mPin2(pin2), mPin3(pin3), mPin4(pin4){
  pinMode(mPin1, OUTPUT);
  pinMode(mPin2, OUTPUT);
  pinMode(mPin3, OUTPUT);
  pinMode(mPin4, OUTPUT);
}

void DirectStepper::nextStep(void){
  digitalWrite(mPin1, PIN1_MASK & mStep);
  digitalWrite(mPin2, PIN2_MASK & mStep);
  digitalWrite(mPin3, PIN3_MASK & mStep);
  digitalWrite(mPin4, PIN4_MASK & mStep);

  if(mIsForward){
    mStep<<=1;
    mStep = mStep == 0 ? B00000001 : mStep;
  }else{
    mStep>>=1;
    mStep = mStep == 0 ? B10000000 : mStep;
  }
}

void DirectStepper::setForward(boolean isForward){
  mIsForward = isForward;
}

boolean DirectStepper::isForward(void){
  return mIsForward;
}

void Counter::setCounts(unsigned int counts){
  mCounts = counts;
}

int Counter::getCounts(void){
  return mCounts;
}

int Counter::next(void){
  return mCounts > 0 ? mCounts-- : mCounts;
}