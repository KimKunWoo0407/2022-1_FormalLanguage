#pragma once

#include "Variables.h"

class Transition_NFA {
public:

	State state;

	int symbol; // �ԽǷ��� char������ �ν�x
	vector<State> nextState;
	Transition_NFA(State state, int symbol, vector<State> nextState);
};

extern vector<Transition_NFA> NFA_Delta;
