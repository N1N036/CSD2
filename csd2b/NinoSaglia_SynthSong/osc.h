#pragma once
#include<iostream>
#define M_PI 3.14159265358979323846


class Osc
{
public:
  // Constructor
  Osc(double frequency, double samplerate);
  // Destructor
  ~Osc();
  double getSample();
  void setFrequency(double frequency);
  void phaseMod(double phase);
  float getFrequency();
  void tick();
  virtual void calculate() = 0;

protected:
  double samplerate;
  double frequency;
  double phase;
  double sample;
};
