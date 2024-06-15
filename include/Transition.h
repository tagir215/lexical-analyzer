#pragma once
#include <vector>
#include "AutomataState.h"

class Transition{
public:
	/*
	* tarkistaa onko kyseinen tila viel‰ kelpaava kyseiseen sanaan. 
	* esim. jos sana alkaa operaattorilla = niin se ei en‰‰ kelpaa Identifier tilaksi, joten 
	* IdentifierTransition implementaatio t‰st‰ palauttaisi false
	*/
	virtual bool execute(AutomataState& state, char c) = 0;
	virtual void reset();
};

