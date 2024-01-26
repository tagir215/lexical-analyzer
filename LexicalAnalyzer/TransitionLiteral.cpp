#include "TransitionLiteral.h"

#include <cctype>

bool TransitionLiteral::execute(AutomataState& state, char c){
    if ((c == '"' || c == '\'') && !quote_open) {
        quote_open = true;
        state.currentState = state.root;
        return true;
    }
    if ((c != '"' && c!= '\'') && quote_open) {
        return true;
    }
    else if ((c == '"' || c == '\'') && quote_open) {
        state.currentState = state.literal;
        quote_open = false;
        return true;
    }

    if (std::isdigit(c)) {
        state.currentState = state.literal;
        return true;
    }

    return false;
}
