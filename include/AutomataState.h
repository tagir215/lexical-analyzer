#pragma once
#include "State.h"

/*
* kokoelma eri tiloista joissa automata voi olla, mutta ei sis�ll� kaikkia mahdollisia tiloja...
*/
struct AutomataState {
	State* root;
	State* currentState;
	State* identifier;
	State* literal;
};
