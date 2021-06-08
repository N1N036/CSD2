
#include "piano.h"

//constructor and destructor

piano::piano(int range,std::string name) : instrument(range,name)
{
  std::cout << "piano range: "
    << range << "\n";
}
piano::~piano()
{
}

// methods
void piano::melody()
{
  std::cout << "de piano speelt een leuk wijsje"<< "\n";
}
