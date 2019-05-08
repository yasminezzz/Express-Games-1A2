#include <SDL/SDL.h>
#include "Characters.h"
int condition_fin(Cha P)
{
if (P.Health==0 || P.MCP.y<680)
return 1;
return 0;
}
