#pragma once
#include <iostream>



class Adsr
{
public:
  //Constructor and destructor
  Adsr(double attackTime, double decayTime, double sustainAmp, double releaseTime);
  ~Adsr();
  
  void noteOn(double Time);
  void noteOff(double Time);
  double getValue(double Time);
  double attackTime;
	double decayTime;
	double sustainAmp;
	double releaseTime;
	double TimeOff = 0;
	double TimeOn = 0;
	bool NoteOnValue = false;

};
