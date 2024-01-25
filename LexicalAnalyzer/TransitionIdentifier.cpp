#include "TransitionIdentifier.h"
#include <cctype>

bool TransitionIdentifier::execute(AutomataState& state, char c){
    if (c == '_' || std::isalpha(c)) {
        state.currentState = state.identifier;
        return true;
    }
    return false;
}
