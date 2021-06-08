#include "wave.h"
#include "math.h"

Wave::Wave(double frequency, double samplerate, int nType) : Osc(frequency, samplerate)
{
  std::cout << "Waveform - constructor" << std::endl;
  std::cout << "nType (waveformtype) =" << nType << std::endl;
  this->nType = nType;
}

Wave::~Wave()
{
  std::cout << "Waveform - destructor" << std::endl;
}

void Wave::setnType(int nType)
{
  this->nType = nType;
}

void Wave::calculate()
{
  //selecting the formula for each type of waveform
  switch (nType)
	{
    case 0: // Sine wave
    {
      sample = sin(M_PI * 2 * phase);
      break;
    }

    case 1: // Square wave
    {
    	sample = sin(M_PI * 2 * phase) > 0 ? 1.0 : -1.0;
      break;
    }

    case 2: // Triangle wave
    {
    	sample = asin(sin(M_PI * 2 * phase)) * (2.0 / M_PI);
      break;
    }

    case 3: // Saw wave
    {
      sample = 0.0;
      for(unsigned int i = 1; i<50; i++)
      {
        sample += (sin(M_PI * 2 * phase * i))/i;
      }
      break;
    }

    case 4: //  noise
    {
    	sample = 2.0 * ((double)rand() / (double)RAND_MAX) - 1.0;
      break;
    }

    default:
    {
    	sample = 0.0;
      break;
    }
  }
}
