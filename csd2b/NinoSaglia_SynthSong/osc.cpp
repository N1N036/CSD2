#define M_PI 3.14159265358979323846
#include "osc.h"
#include "math.h"

// Constructor
Osc::Osc(double frequency, double samplerate) : frequency(frequency), samplerate(samplerate)
  {
    std::cout << "Oscillator begins" << std::endl;
}

// Destructor
Osc::~Osc()
{
  std::cout << "Oscillator ends" << std::endl;
}

void Osc::tick()
{
  phase += frequency/samplerate;
  if (phase > 1.0)
  {
    phase -= 1.0;
  }
  //calculating the waveform
  calculate();
}

double Osc::getSample()
{
    return sample;
}

void Osc::setFrequency(double frequency)
{
  this->frequency = frequency;
}

void Osc::phaseMod(double phase)
{
  this->phase += phase;
}


float Osc::getFrequency()
{
  return frequency;
}
