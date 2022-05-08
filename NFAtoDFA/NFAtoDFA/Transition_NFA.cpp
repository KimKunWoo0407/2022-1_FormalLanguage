#include "Transition_NFA.h"

Transition_NFA::Transition_NFA(State state, int symbol, vector<State> nextState) {
	this->state = state;
	this->symbol = symbol;
	this->nextState = nextState;
}

vector<Transition_NFA> NFA_Delta = {};