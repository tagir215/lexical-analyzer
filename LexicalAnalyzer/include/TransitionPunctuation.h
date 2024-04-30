#pragma once
#include "AutomataState.h"
#include "Transition.h"

class TransitionPunctuation : public Transition{
public:
	bool execute(AutomataState& state, char c) override;
};

