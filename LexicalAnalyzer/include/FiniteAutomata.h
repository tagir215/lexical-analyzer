#pragma once
#include "State.h"
#include <string>
#include "Transition.h"
#include "AutomataState.h"
#include "TokenType.h"

/*
* Pit‰‰ ylh‰‰ll‰ ja k‰sittelee t‰m‰n hetkist‰ tilaa.
*/
class FiniteAutomata{
public:
	AutomataState state;
	
	FiniteAutomata();
	~FiniteAutomata();
	
	/*
	* k‰sittelee seuraavan kirjaimen sanasta
	*/
	bool operator <<(char c);
	/*
	*  alustaa state takaisin juureen
	*/
	void operator --();
	/*
	* tarkistaa onko senhetkinen state kelpaava
	*/
	bool operator &();

	/*
	* k‰yt‰nnˆss‰ lis‰‰ uuden keywordin luokkaan jotka automata laskee myˆs kelpaaviksi tiloiksi
	*/
	void insert(std::string word, TokenType tokenType);

private:
	std::vector<Transition*>transitions;

};

