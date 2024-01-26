#include "TransitionIdentifier.h"
#include <cctype>

bool TransitionIdentifier::execute(AutomataState& state, char c){
    if (c == '_' || std::isalpha(c)) {
        state.currentState = state.identifier;
        return true;
    }
    else if (!state.currentState->isAllowed && state.currentState->type == "KEYWORD") {
        state.currentState = state.identifier;
    }
    return false;
}
