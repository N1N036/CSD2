#include "adsr.h"
#include "math.h"

Adsr::Adsr(double attackTime, double decayTime, double sustainAmp, double releaseTime)
  {
  std::cout << "Adsr - constructor" << std::endl;
  this->attackTime = attackTime;
  this->decayTime = decayTime;
  this->sustainAmp = sustainAmp;
  this->releaseTime = releaseTime;
  }

Adsr::~Adsr()
{
  std::cout << "Adsr - destructor" << std::endl;
}




// Call when key is pressed
void Adsr::noteOn(double Time)
{
TimeOn = Time;
NoteOnValue = true;
}

// Call when key is released
void Adsr::noteOff(double Time)
{
TimeOff = Time;
NoteOnValue = false;
}


double Adsr::getValue(double Time)
{
  double amplitude = 0.0;
  double lifeTime = Time - TimeOn;


  if (NoteOnValue)
  {
    if (lifeTime <= attackTime)
    {
      // In attack Phase - approach max amplitude
      amplitude = lifeTime / attackTime;

    }

    if (lifeTime > attackTime && lifeTime <= (attackTime + decayTime))
    {
      // In decay phase - reduce to sustained amplitude
      amplitude = ((lifeTime - attackTime) / decayTime) * (sustainAmp - 1) + 1;

    }

    if (lifeTime > (attackTime + decayTime))
    {
      // In sustain phase - dont change until note released
      amplitude = sustainAmp;

    }
  }
  else
  {
    // Note has been released, so in release phase
    amplitude = ((Time - TimeOff) / releaseTime) * (0.0 - sustainAmp) + sustainAmp;

  }

  // Amplitude should not be negative
  if (amplitude <= 0.0001)
    amplitude = 0.0;

  return amplitude;
}
