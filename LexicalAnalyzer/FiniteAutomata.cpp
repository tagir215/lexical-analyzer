#include "FiniteAutomata.h"
#include "TransitionKeyword.h"
#include "TransitionIdentifier.h"

FiniteAutomata::FiniteAutomata() {
	state.root = new State("");
	state.identifier = new State("IDENTIFIER");
	state.identifier->isAllowed = true;

	state.currentState = state.root;
	transitions.push_back(new TransitionKeyword());
	transitions.push_back(new TransitionIdentifier());
}

FiniteAutomata::~FiniteAutomata(){

}

bool FiniteAutomata::operator <<(char c) {
	bool stateChanged = false;
	for (Transition* transition : transitions) {
		if (transition->execute(state, c)) {
			return true;
		}
	}
	return stateChanged;
}
void FiniteAutomata::operator --() {
	state.currentState = state.root;
}

bool FiniteAutomata::operator &(){
	return state.currentState->isAllowed;
}


void FiniteAutomata::insert(std::string word){
	state.currentState = state.root;
	for (char c : word) {
		if (state.currentState->childStates.find(c) == state.currentState->childStates.end()) {
			state.currentState->childStates[c] = new State("KEYWORD");
		}
		state.currentState = state.currentState->childStates[c];
	}
	state.currentState->isAllowed = true;
}
