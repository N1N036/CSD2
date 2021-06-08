#pragma once
#include"osc.h"
#include <iostream>



class Sine : public Osc
{
public:
  //Constructor and destructor
  Sine(double frequency, double samplerate);
  ~Sine();
  // go to next sample
  void calculate();
};
