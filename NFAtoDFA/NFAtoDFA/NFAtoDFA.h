#pragma once

#include "Transition_NFA.h"
#include "Transition_DFA.h"
#include "Transition_Reduced_DFA.h"


extern DfaState TransitionResult(DfaState state, int symbol);
extern void makeDFA_Delta(vector<State> dfaq, int symbol);
extern void makeEpsilonClosure(State current);
extern void matchEpsilonClosure(State state);
extern void makeDFA_F();
extern void epsilonNFAtoDFA();
extern int GroupNumber(DfaState state);
extern vector<R_DfaState> Grouping(R_DfaState group, int sigma);
extern void DFAtoReduceDFA();