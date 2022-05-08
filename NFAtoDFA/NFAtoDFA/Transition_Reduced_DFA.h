#pragma once

#include "Variables.h";

class Transition_Reduced_DFA {
public:

	R_DfaState state;
	int symbol;
	R_DfaState nextState;
	Transition_Reduced_DFA(R_DfaState state, int symbol, R_DfaState nextState);

	Transition_Reduced_DFA(R_DfaState state, int symbol, DfaState nextState);

};

extern vector<Transition_Reduced_DFA> Reduced_DFA_Delta;
