#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef string State;
typedef vector<State> DfaState;
typedef vector<DfaState> R_DfaState;

vector<State> NFA_Q;
map<State, vector<State>> epsilon_closure_map;

vector<DfaState> DFA_Q;
vector<R_DfaState> ReducedDFA_Q;

vector<int> Sigma;

State startState;
DfaState DFA_startState;
R_DfaState ReducedDFA_startState;

vector<State> NFA_F;
vector<DfaState> DFA_F;
vector<R_DfaState> ReducedDFA_F;

vector<State> epsilon_closure;

vector<R_DfaState> Group(2);

class Transition_NFA {
public:

	State state;

	int symbol; // 입실론은 char형으로 인식x
	vector<State> nextState;
	Transition_NFA(State state, int symbol, vector<State> nextState) {
		this->state = state;
		this->symbol = symbol;
		this->nextState = nextState;
	}
};

vector<Transition_NFA> NFA_Delta;

class Transition_DFA {
public:

	DfaState state;
	int symbol;
	DfaState nextState;
	Transition_DFA(DfaState state, int symbol, DfaState nextState) {
		this->state = state;
		this->symbol = symbol;
		this->nextState = nextState;
	}

	Transition_DFA(State state, int symbol, State nextState) {
		this->state.push_back(state);
		this->symbol = symbol;
		this->nextState.push_back(nextState);
	}

};

vector<Transition_DFA> DFA_Delta;

class Transition_Reduced_DFA {
public:

	R_DfaState state;
	int symbol;
	R_DfaState nextState;
	Transition_Reduced_DFA(R_DfaState state, int symbol, R_DfaState nextState) {
		this->state = state;
		this->symbol = symbol;
		this->nextState = nextState;
	}

	Transition_Reduced_DFA(R_DfaState state, int symbol, DfaState nextState) {
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

};

vector<Transition_Reduced_DFA> Reduced_DFA_Delta;

DfaState TransitionResult(DfaState state, int symbol);
void makeDFA_Delta(vector<State> dfaq, int symbol);
void makeEpsilonClosure(State current);
void matchEpsilonClosure(State state);
void makeDFA_F();
void epsilonNFAtoDFA();
int GroupNumber(DfaState state);
vector<R_DfaState> Grouping(R_DfaState group, int sigma);
void DFAtoReduceDFA();