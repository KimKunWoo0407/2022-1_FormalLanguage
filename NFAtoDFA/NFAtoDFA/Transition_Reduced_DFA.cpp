#include "Transition_Reduced_DFA.h"

Transition_Reduced_DFA::Transition_Reduced_DFA(R_DfaState state, int symbol, R_DfaState nextState) {
	this->state = state;
	this->symbol = symbol;
	this->nextState = nextState;
}

Transition_Reduced_DFA::Transition_Reduced_DFA(R_DfaState state, int symbol, DfaState nextState) {
	this->state = state;
	this->symbol = symbol;
	for (int i = 0; i < ReducedDFA_Q.size(); i++)
	{
		if (find(ReducedDFA_Q[i].begin(), ReducedDFA_Q[i].end(), nextState) != ReducedDFA_Q[i].end())
		{
			this->nextState = ReducedDFA_Q[i];
			break;
		}
	}
}

vector<Transition_Reduced_DFA> Reduced_DFA_Delta = {};