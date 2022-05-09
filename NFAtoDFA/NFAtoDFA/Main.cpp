#include "NFAtoDFA.h"

int main()
{
	/*NFA_Q = { "1","2","3","4" };
	Sigma = { 'a','b','c', 'ュ' };

	NFA_Delta = {
		Transition_NFA("1", 'ュ', { "3" }),
		Transition_NFA("3", 'ュ', { "4" })
		Transition_NFA("1", 'a', { "2" }),
		Transition_NFA("2", 'b', { "4" }),
		Transition_NFA("3", 'c', { "3" })
	};

	startState = { "1" };

	NFA_F = { "4" };

	epsilonNFAtoDFA();*/

	//DFA_Q = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"} };
	///*Sigma = { 'a','b','c', 'ュ' };*/\
	//	Sigma = { 'a','b' };


	//DFA_Delta = {
	//	Transition_DFA("A", 'a', "F"),
	//	Transition_DFA("A", 'b', "B"),
	//	Transition_DFA("B", 'a', "E"),
	//	Transition_DFA("B", 'b', "D"),
	//	Transition_DFA("C", 'a', "C"),
	//	Transition_DFA("C", 'b', "F"),
	//	Transition_DFA("D", 'a', "D"),
	//	Transition_DFA("D", 'b', "A"),
	//	Transition_DFA("E", 'a', "B"),
	//	Transition_DFA("E", 'b', "C"),
	//	Transition_DFA("F", 'a', "A"),
	//	Transition_DFA("F", 'b', "E"),
	//};

	//DFA_startState = { "A" };

	//DFA_F = { {"A"}, {"F"} };



	DFA_Q = { {"A"},{"B"},{"C"},{"D"},{"E"} };
	/*Sigma = { 'a','b','c', 'ュ' };*/\
		Sigma = { 'a','b' };


	DFA_Delta = {
		Transition_DFA("A", 'a', "B"),
		Transition_DFA("A", 'b', "D"),
		Transition_DFA("B", 'a', "B"),
		Transition_DFA("B", 'b', "C"),
		Transition_DFA("C", 'a', "D"),
		Transition_DFA("C", 'b', "E"),
		Transition_DFA("D", 'a', "D"),
		Transition_DFA("D", 'b', "E"),
		Transition_DFA("E", 'a', "B"),
		Transition_DFA("E", 'b', "C"),
	};

	DFA_startState = { "A" };

	DFA_F = { {"C"}, {"E"} };

	DFAtoReduceDFA();

}