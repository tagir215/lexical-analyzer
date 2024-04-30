#pragma once
#include "Transition.h"
class TransitionIdentifier : public Transition{
public:
	bool execute(AutomataState& state, char c) override;
};

