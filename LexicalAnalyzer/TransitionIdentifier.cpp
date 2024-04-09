#include "TransitionIdentifier.h"
#include <cctype>

bool TransitionIdentifier::execute(AutomataState& state, char c){
    if (state.currentState->tokenType == TokenType::OPERATOR 
        || state.currentState->tokenType == TokenType::PUNCTUATION) {
        return false;
    }
    if (c == '_' || std::isalpha(c) || std::isdigit(c)) {
        state.currentState = state.identifier;
        return true;
    }
    else if (!state.currentState->isAllowed && state.currentState->tokenType == TokenType::KEYWORD) {
        state.currentState = state.identifier;
    }
    return false;
}
