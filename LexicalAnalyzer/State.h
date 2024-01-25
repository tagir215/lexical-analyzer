#pragma once
#include <vector>
#include <unordered_map>
#include <string>

struct State {
	std::unordered_map<char,State*>childStates;
	bool isAllowed;
	std::string type;

	State(std::string type) : type(type) {
		isAllowed = false;
	}
};
