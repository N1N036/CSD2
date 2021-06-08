good:

c++ :

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



--------------------------------------------

bad:


python:

python code:
for i in range(0,1000000):
    print(t.time()-s)
    print(t.time())


c++ :

double frequency = 220; //initialise first frequency
double octaveBaseFrequency = 110.0; // A2 base frequency for calculation
double d12thRootOf2 = pow(2.0, 1.0 / 12.0);		//12th root of 2
bool keyboardToggle = 1; //for toggling the acsi keyboard
int synthState = 0; //select what kind of synth you want
bool melodyToggle = 0; //for toggling the melody generator
double melodyTrigTime = 0.0; //init melody trigger
int Buf[1000];

