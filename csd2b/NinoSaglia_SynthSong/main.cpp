#include <iostream>
#include <thread>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <Windows.h>

#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "wave.h"
#include "adsr.h"


double frequency = 220; //initialise first frequency
double octaveBaseFrequency = 110.0; // A2 base frequency for calculation
double d12thRootOf2 = pow(2.0, 1.0 / 12.0);		//12th root of 2
bool keyboardToggle = 1; //for toggling the acsi keyboard
int synthState = 0; //select what kind of synth you want
bool melodyToggle = 0; //for toggling the melody generator
double melodyTrigTime = 0.0; //init melody trigger


int main(int argc,char **argv)
{

  std::cout << std::endl <<
    "|   |   |   |   |   | |   |   |   |   | |   | |   |   |   |" << std::endl <<
    "|   | S |   |   | F | | G |   |   | J | | K | | L |   |   |" << std::endl <<
    "|   |___|   |   |___| |___|   |   |___| |___| |___|   |   |__" << std::endl <<
    "|     |     |     |     |     |     |     |     |     |     |" << std::endl <<
    "|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |" << std::endl <<
    "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << std::endl << std::endl;


  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init("example.exe");
  double samplerate = jack.getSamplerate();

  //Waveforms
  Wave saw(0, samplerate, 3);
  Sine sine1(0, samplerate);
  Sine sine2(0, samplerate);
  Wave white(0, samplerate, 4);

  //envelopes
  Adsr adsr1(0.01, 0.1, 0.5, 1);
  Adsr adsr2(0.001, 0.06, 0.0, 0.001);

  double CurrentTimeS = 0.0;  //init start time in seconds
  int CurrentSamp = 0;//declare the first sample

  //wat leuke text en info:
  std::cout << std::endl;
  std::cout << "\n\nPress 'q' when you want to quit the program."<<std::endl;
  std::cout << std::endl;
  std::cout << "Press'1' to toggle the qwerty keyboard input" << std::endl;
  std::cout << std::endl;
  std::cout << "Press'2' to toggle the melody" << std::endl;
  std::cout << std::endl;
  std::cout << "Press'3' to toggle between synth presets" << std::endl;


  //assign a function to the JackModule::onProces
  jack.onProcess = [&saw, &sine1, &sine2, &white, &samplerate, &CurrentTimeS, &CurrentSamp, &adsr1, &adsr2](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {

      if (synthState == 1)
      {
        //synth state 1
        outBuf[i] = saw.getSample() * 0.1 * adsr1.getValue(CurrentTimeS);
        saw.tick();
        sine1.tick();
        saw.setFrequency((frequency + sine1.getSample()));
        sine1.setFrequency(frequency/10);
      }
      else
      {
        outBuf[i] =
        (
          //synthstate 2
          sine1.getSample() * 0.1 * adsr1.getValue(CurrentTimeS) +
          white.getSample() * 0.03 * adsr2.getValue(CurrentTimeS)
        );
        sine1.phaseMod(saw.getSample()*0.02*adsr1.getValue(CurrentTimeS) + saw.getSample()*0.01*sine2.getSample());
        sine1.tick();
        sine2.tick();
        saw.tick();
        sine1.setFrequency(frequency);
        sine2.setFrequency(frequency/2);
        saw.setFrequency(frequency);
        white.tick();

      }
      CurrentSamp += 1;
      CurrentTimeS = CurrentSamp / samplerate;

    }

    return 0;
  };

  jack.autoConnect();


  //keep the program running and listen for user input, q = quit

  bool running = true;
  int nCurrentKey = -1;
	bool bKeyPressed = false;
  while (running)
  {
    //live keyboard in
    bKeyPressed = false;
    for (int k = 0; k < 16; k++)
    {
      if (keyboardToggle)
      {
        if (GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe\xbf"[k])) & 0x8000)
        {
          if (nCurrentKey != k)
          {
            frequency = octaveBaseFrequency * pow(d12thRootOf2, k);
            adsr1.noteOn(CurrentTimeS);
            adsr2.noteOn(CurrentTimeS);
            nCurrentKey = k;
          }
          bKeyPressed = true;
        }

        //melody generator
        if(melodyToggle)
        {
          if (CurrentTimeS >= melodyTrigTime)
          {
            k += (rand() % 2) - 1;
            frequency = octaveBaseFrequency * pow(d12thRootOf2, k);
            melodyTrigTime = (CurrentTimeS + 0.5);

            bKeyPressed = true;
            adsr1.noteOn(CurrentTimeS);
            adsr2.noteOn(CurrentTimeS);
          }
        }
      }
    }
    //quit the program
    if (GetAsyncKeyState('Q') & 0x8000)
    {
      running = false;
      jack.end();
      break;
    }
    //1 for toggling the keyboard
    else if (GetAsyncKeyState('1') & 0x8000)
    {
      if (nCurrentKey != -2)
      {
        if (!keyboardToggle)
        {
          std::cout << std::endl <<
            "|   |   |   |   |   | |   |   |   |   | |   | |   |   |   |" << std::endl <<
            "|   | S |   |   | F | | G |   |   | J | | K | | L |   |   |" << std::endl <<
            "|   |___|   |   |___| |___|   |   |___| |___| |___|   |   |__" << std::endl <<
            "|     |     |     |     |     |     |     |     |     |     |" << std::endl <<
            "|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |" << std::endl <<
            "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << std::endl << std::endl;
          std::cout<<"keyboard: on"<<std::endl;
          keyboardToggle = true;
        }
        else
        {
          std::cout<<"keyboard: off"<<std::endl;
          keyboardToggle = false;
        }
      }
      nCurrentKey = -2;
      bKeyPressed = true;
    }
    //2 for toggling the melody
    else if (GetAsyncKeyState('2') & 0x8000)
    {
      if (nCurrentKey != -3)
      {
        if (!melodyToggle)
        {
          std::cout<<"melody: on"<<std::endl;
          melodyToggle = true;
        }
        else
        {
          std::cout<<"melody: off"<<std::endl;
          melodyToggle = false;
        }
      }
      nCurrentKey = -3;
      bKeyPressed = true;
    }
    //3 for selecting synthstate
    else if (GetAsyncKeyState('3') & 0x8000)
    {
      if (nCurrentKey != -4)
      {
        if (synthState != 1)
        {
          std::cout<<"synth: 1"<<std::endl;
          synthState = 1;
        }
        else
        {
          std::cout<<"synth: 2"<<std::endl;
          synthState = 2;
        }
      }
      nCurrentKey = -4;
      bKeyPressed = true;
    }

    //must be last: resetting values for toggling and sending note off value
    if (!bKeyPressed)
    {
      if (nCurrentKey != -1)
      {
        adsr1.noteOff(CurrentTimeS);
        adsr2.noteOff(CurrentTimeS);
        nCurrentKey = -1;
      }
    }
  }

  //end the program
  return 0;
} // main()
