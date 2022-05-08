#include "Transition_DFA.h"

Transition_DFA::Transition_DFA(DfaState state, int symbol, DfaState nextState) {
	this->state = state;
	this->symbol = symbol;
	this->nextState = nextState;
}

Transition_DFA::Transition_DFA(State state, int symbol, State nextState) {
	this->state.push_back(state);
	this->symbol = symbol;
	this->nextState.push_back(nextState);
}

vector<Transition_DFA> DFA_Delta = {};