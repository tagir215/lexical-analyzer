#pragma once
#include "State.h"

struct AutomataState {
	State* root;
	State* currentState;
	State* identifier;
};
