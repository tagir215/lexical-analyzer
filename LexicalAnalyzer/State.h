#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "TokenType.h"

struct State {
	std::unordered_map<char,State*>childStates;
	bool isAllowed;
	TokenType tokenType;

	State(TokenType tokenType) : tokenType(tokenType) {
		isAllowed = false;
	}
};
