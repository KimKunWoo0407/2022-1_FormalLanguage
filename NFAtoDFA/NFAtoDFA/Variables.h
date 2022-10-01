#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef string State; // ε-NFA의 상태
typedef vector<State> DfaState; // DFA의 상태
typedef vector<DfaState> R_DfaState; // Reduced DFA의 상태 

extern vector<State> NFA_Q; // ε-NFA의 상태집합
extern map<State, vector<State>> epsilon_closure_map; // ε-closure 저장 공간

extern vector<DfaState> DFA_Q; // DFA의 상태집합
extern vector<R_DfaState> ReducedDFA_Q; // Reduced DFA의 상태집합

extern vector<int> Sigma; // 인식하는 심볼

extern State startState; // ε-NFA의 시작 상태
extern DfaState DFA_startState; // DFA의 시작상태
extern R_DfaState ReducedDFA_startState; // Reduced DFA의 시작상태

extern vector<State> NFA_F; // ε-NFA의 종결 상태 집합
extern vector<DfaState> DFA_F; // DFA의 종결 상태 집합
extern vector<R_DfaState> ReducedDFA_F; // Reduced DFA의 종결 상태 집합

extern vector<State> epsilon_closure; // 임시 공간

extern vector<R_DfaState> Group; // 임시 공간