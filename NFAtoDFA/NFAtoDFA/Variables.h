#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef string State; // ��-NFA�� ����
typedef vector<State> DfaState; // DFA�� ����
typedef vector<DfaState> R_DfaState; // Reduced DFA�� ���� 

extern vector<State> NFA_Q; // ��-NFA�� ��������
extern map<State, vector<State>> epsilon_closure_map; // ��-closure ���� ����

extern vector<DfaState> DFA_Q; // DFA�� ��������
extern vector<R_DfaState> ReducedDFA_Q; // Reduced DFA�� ��������

extern vector<int> Sigma; // �ν��ϴ� �ɺ�

extern State startState; // ��-NFA�� ���� ����
extern DfaState DFA_startState; // DFA�� ���ۻ���
extern R_DfaState ReducedDFA_startState; // Reduced DFA�� ���ۻ���

extern vector<State> NFA_F; // ��-NFA�� ���� ���� ����
extern vector<DfaState> DFA_F; // DFA�� ���� ���� ����
extern vector<R_DfaState> ReducedDFA_F; // Reduced DFA�� ���� ���� ����

extern vector<State> epsilon_closure; // �ӽ� ����

extern vector<R_DfaState> Group; // �ӽ� ����