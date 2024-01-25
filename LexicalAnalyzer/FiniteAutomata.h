#pragma once
#include "State.h"
#include <string>
#include "Transition.h"
#include "AutomataState.h"


class FiniteAutomata{
public:
	AutomataState state;
	
	FiniteAutomata();
	~FiniteAutomata();
	
	bool operator <<(char c);
	void operator --();
	bool operator &();

	void insert(std::string word);

private:
	std::vector<Transition*>transitions;

};

