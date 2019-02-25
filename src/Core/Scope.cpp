#include "Scope.h"

/*
#0,0,0
{ #0,1,0
	global a # 0,1,0
	global b # 0,1,0
	global c # 0,1,0
}

{ #1,1,0
	global x # 1,1,0
	global y # 1,1,0
	global z # 1,1,0
}
*/

/*
Returns true if other scope object can be reached
*/
bool Scope::CanReach(Scope scope)
{
	Scope Parent;
	return false;
}