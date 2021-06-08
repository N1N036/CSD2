#pragma once
#include"osc.h"
#include <iostream>



class Wave : public Osc
{
public:
  //Constructor and destructor
  Wave(double frequency, double samplerate, int nType = 0);
  ~Wave();
  void setnType(int nType);
  void calculate();

private:
  int nType;

};
