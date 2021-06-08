
#include "instrument.h"

class guitar : public instrument
{
public:
  //constructor and destructor
  guitar(int range,std::string name);
  ~guitar();

  // methods
  void solo();
  void solomellow();
};
