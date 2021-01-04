#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <iostream>

class instrument
{
public:
  // constructor and destructor
  instrument(int range,std::string name);
  ~instrument();

  // methods
  void play();
  void pause();
protected:
  int range;
  std::string name;
};

#endif
