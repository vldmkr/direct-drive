#ifndef DIRECT_STEPPER_H
#define DIRECT_STEPPER_H

#include <Arduino.h>

#define PIN1_MASK B11100000
#define PIN2_MASK B00111000
#define PIN3_MASK B00001110
#define PIN4_MASK B10000011

class DirectStepper
{
public:
  DirectStepper(byte pin1, byte pin2, byte pin3, byte pin4);
  void nextStep(void);
  void setForward(boolean isForward);
  boolean isForward(void);

private:
  boolean mIsForward = true;
  byte mStep = B00000001;
  byte mPin1, mPin2, mPin3, mPin4;
};

class Counter{
public:
  void setCounts(unsigned int counts);
  int getCounts(void);
  int next(void);
private:
  unsigned int mCounts = 0;
};

#endif //DIRECT_STEPPER_H