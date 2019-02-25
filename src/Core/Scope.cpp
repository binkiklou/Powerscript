//#include "Scope.h" <--- Wow i dont know how I did that but, I did it 
#include "Powerscript.h"

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

namespace Powerscript
{
	bool Env::Scope_Reach(Scope scope)
	{
		return false;
	}
	Scope Env::Scope_By_Id(int id)
	{
		int Cid = 0; // current id
		Scope scope;
		for (std::vector<Scope>::iterator s = this->ScopeList.begin(); s != this->ScopeList.end(); ++s)
		{
			scope = *s;
			Cid++;

			if (Cid == scope.id)
			{
				return scope;
			}
		}
		return scope;
	}
}