#pragma once
#include "Variables.h"

class Transition_DFA {
public:

	DfaState state;
	int symbol;
	DfaState nextState;
	Transition_DFA(DfaState state, int symbol, DfaState nextState);

	Transition_DFA(State state, int symbol, State nextState);

};

extern vector<Transition_DFA> DFA_Delta;