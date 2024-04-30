#pragma once
#include "Transition.h"
class TransitionKeyword : public Transition{
public:
	bool execute(AutomataState& state, char c) override;
};

