
#include "guitar.h"
#include "piano.h"
#include "bass.h"

int main ()
{
  guitar aGuitar(12,"schredder100");
  aGuitar.play();
  aGuitar.solo();

  guitar bGuitar(12,"semi versterkt");
  bGuitar.play();
  bGuitar.solomellow();

  piano aPiano(36,"steinway");
  aPiano.play();
  aPiano.melody();

  bass aBass(12,"fleabass");
  aBass.play();
  aBass.funk();

  // end program
  return 0;
}
