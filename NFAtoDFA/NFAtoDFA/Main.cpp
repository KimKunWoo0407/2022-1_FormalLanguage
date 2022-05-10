#include "NFAtoDFA.h"

int main()
{
	NFA_Q = { "P","Q","R","S", "T", "U"};
	Sigma = { '0','1', '��' };

	NFA_Delta = {
		Transition_NFA("P", '��', { "Q","S"}),
		Transition_NFA("Q", '0', { "R" }),
		Transition_NFA("Q", '1', { "Q" }),
		Transition_NFA("R", '0', { "Q" }),
		Transition_NFA("R", '1', { "R" }),
		Transition_NFA("S", '0', { "S" }),
		Transition_NFA("S", '1', { "T" }),
		Transition_NFA("T", '0', { "T" }),
		Transition_NFA("T", '1', { "S" }),
		Transition_NFA("Q", '��', { "U" }),
		Transition_NFA("S", '��', { "U" }),
	};

	startState = { "P" };

	NFA_F = { "U" };


	epsilonNFAtoDFA();

	DFAtoReducedDFA();

	printResult('A');

}