#include "TransitionPunctuation.h"


bool TransitionPunctuation::execute(AutomataState& state, char c) {
	if (state.currentState->childStates.find(c) != state.currentState->childStates.end()) {
		state.currentState = state.currentState->childStates[c];
		return true;
	}
	return false;
}
