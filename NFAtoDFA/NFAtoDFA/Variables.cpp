#include "Variables.h"

vector<State> NFA_Q = {};
map<State, vector<State>> epsilon_closure_map = {};

vector<DfaState> DFA_Q = {};
vector<R_DfaState> ReducedDFA_Q = {};

vector<int> Sigma = {};

State startState = "";
DfaState DFA_startState = {};
R_DfaState ReducedDFA_startState = {};

vector<State> NFA_F = {};
vector<DfaState> DFA_F = {};
vector<R_DfaState> ReducedDFA_F = {};

vector<State> epsilon_closure = {};
vector<R_DfaState> Group(2);