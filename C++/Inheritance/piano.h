
#include "instrument.h"

class piano : public instrument
{
public:
  //constructor and destructor
  piano(int range,std::string name);
  ~piano();

  // methods
  void melody();
};
