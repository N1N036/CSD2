
#include "bass.h"

//constructor and destructor

bass::bass(int range,std::string name) : instrument(range,name)
{
  std::cout << "bass range: "
    << range << "\n";
}
bass::~bass()
{
}

// methods
void bass::funk()
{
  std::cout << "de bass speelt een funky ritme"<< "\n";
}
