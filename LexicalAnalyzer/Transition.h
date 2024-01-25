#pragma once
#include <vector>
#include "AutomataState.h"
class Transition{
public:
	virtual bool execute(AutomataState& state, char c) = 0;
};

