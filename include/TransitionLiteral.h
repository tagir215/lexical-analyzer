#pragma once
#include "Transition.h"

class TransitionLiteral : public Transition{
public:
	bool execute(AutomataState& state, char c) override;
private:
	bool quote_open = false;
	bool number_open = false;

};

