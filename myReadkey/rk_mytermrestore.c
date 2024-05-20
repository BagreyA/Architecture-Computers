#include "myReadkey.h"
#include "rk.h"

int
rk_myTermRestore ()
{
  return tcsetattr (0, TCSANOW, &termTemp);
}