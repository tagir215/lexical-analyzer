#include "FiniteAutomata.h"
#include "TransitionKeyword.h"
#include "TransitionIdentifier.h"
#include "TransitionLiteral.h"

FiniteAutomata::FiniteAutomata() {
	state.root = new State(TokenType::NONE);
	state.identifier = new State(TokenType::IDENTIFIER);
	state.identifier->isAllowed = true;
	state.literal = new State(TokenType::LITERAL);
	state.literal->isAllowed = true;

	state.currentState = state.root;
	transitions.push_back(new TransitionLiteral());
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
	for (Transition* transition : transitions) {
		transition->reset();
	}
}

bool FiniteAutomata::operator &(){
	return state.currentState->isAllowed;
}

void FiniteAutomata::insert(std::string word, TokenType tokenType){
	state.currentState = state.root;
	for (char c : word) {
		if (state.currentState->childStates.find(c) == state.currentState->childStates.end()) {
			state.currentState->childStates[c] = new State(tokenType);
		}
		state.currentState = state.currentState->childStates[c];
	}
	if (state.currentState != state.root) {
		state.currentState->isAllowed = true;
	}
}
