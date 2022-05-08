#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef string State;
typedef vector<State> DfaState;
typedef vector<DfaState> R_DfaState;

extern vector<State> NFA_Q;
extern map<State, vector<State>> epsilon_closure_map;

extern vector<DfaState> DFA_Q;
extern vector<R_DfaState> ReducedDFA_Q;

extern vector<int> Sigma;

extern State startState;
extern DfaState DFA_startState;
extern R_DfaState ReducedDFA_startState;

extern vector<State> NFA_F;
extern vector<DfaState> DFA_F;
extern vector<R_DfaState> ReducedDFA_F;

extern vector<State> epsilon_closure;

extern vector<R_DfaState> Group;