
#include "instrument.h"

class bass : public instrument
{
public:
  //constructor and destructor
  bass(int range,std::string name);
  ~bass();

  // methods
  void funk();
};
