#pragma once

#include "Variables.h"

class Transition_NFA {
public:

	State state;

	int symbol; // 입실론은 char형으로 인식x
	vector<State> nextState;
	Transition_NFA(State state, int symbol, vector<State> nextState);
};

extern vector<Transition_NFA> NFA_Delta;
