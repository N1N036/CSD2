
#include "guitar.h"

//constructor and destructor

guitar::guitar(int range,std::string name) : instrument(range,name)
{
  std::cout << "guitar range: "
    << range << "\n";
}
guitar::~guitar()
{
}

// methods
void guitar::solo()
{
  std::cout << "deze gitaar gaat helemaal lossss"<< "\n";
}
void guitar::solomellow()
{
  std::cout << "deze gitaar speelt rustig mee"<< "\n";
}
