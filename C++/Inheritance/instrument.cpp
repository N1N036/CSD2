
#include "instrument.h"

//constructor and destructor
instrument::instrument(int range,std::string name)
{
  std::cout << "constructing instrument" << "\n";
  this->range = range;
  this->name = name;
}

instrument::~instrument()
{
}

void instrument::play()
{
  std::cout << name << " is aan het spelen\n";
}
void instrument::pause()
{
  std::cout << name << " is gepauzeerd\n";
}
