#include "NFAtoDFA.h"

DfaState TransitionResult(DfaState state, int symbol)
{
	for (vector<Transition_DFA>::iterator it = DFA_Delta.begin(); it != DFA_Delta.end(); it++)
	{
		if (it->state == state && it->symbol == symbol)
			return it->nextState;
	}
	return { "フ" };
}

void makeDFA_Delta(vector<State> dfaq, int symbol)
{
	vector<State> nextState;
	vector<State> closure;
	for (vector<State>::iterator it = dfaq.begin(); it != dfaq.end(); it++)
	{
		for (vector<Transition_NFA>::iterator Nit = NFA_Delta.begin(); Nit != NFA_Delta.end(); Nit++)
		{
			if (Nit->state == *it && Nit->symbol == symbol)
			{
				for (vector<State>::iterator sit = Nit->nextState.begin(); sit != Nit->nextState.end(); sit++)
					if (find(nextState.begin(), nextState.end(), *sit) == nextState.end())
						nextState.push_back(*sit);

			}

		}
	}

	if (nextState.size() == 0) return;

	for (vector<State>::iterator sit = nextState.begin(); sit != nextState.end(); sit++)
		closure.insert(closure.end(), epsilon_closure_map[*sit].begin(), epsilon_closure_map[*sit].end());

	sort(closure.begin(), closure.end());
	unique(closure.begin(), closure.end());


	if (find(DFA_Q.begin(), DFA_Q.end(), closure) == DFA_Q.end())
		DFA_Q.push_back(closure);

	DFA_Delta.push_back(Transition_DFA(dfaq, symbol, closure));


}

void makeEpsilonClosure(State current) {

	for (vector<Transition_NFA>::iterator Nit = NFA_Delta.begin(); Nit != NFA_Delta.end(); Nit++)
		if (Nit->state == current && Nit->symbol == 'ュ')
			for (vector<State>::iterator it = Nit->nextState.begin(); it != Nit->nextState.end(); it++)
				if (find(epsilon_closure.begin(), epsilon_closure.end(), *it) == epsilon_closure.end())
				{
					epsilon_closure.push_back(*it);
					makeEpsilonClosure(*it);
				}

}

void matchEpsilonClosure(State state)
{
	epsilon_closure.push_back(state);
	makeEpsilonClosure(state);
	sort(epsilon_closure.begin(), epsilon_closure.end());
	epsilon_closure_map[state] = epsilon_closure;
	epsilon_closure.clear();
}

void makeDFA_F()
{
	for (int idx = 0; idx < DFA_Q.size(); idx++)
	{
		for (vector<State>::iterator it = NFA_F.begin(); it != NFA_F.end(); it++)
			if (find(DFA_Q[idx].begin(), DFA_Q[idx].end(), *it) != DFA_Q[idx].end())
			{
				DFA_F.push_back(DFA_Q[idx]);
				break;
			}
	}
}

void epsilonNFAtoDFA()
{
	for (vector<State>::iterator it = NFA_Q.begin(); it != NFA_Q.end(); it++)
		matchEpsilonClosure(*it);

	DFA_Q.push_back(epsilon_closure_map[startState]);
	DFA_startState = epsilon_closure_map[startState];

	for (int idx = 0; idx < DFA_Q.size(); idx++)
	{
		for (vector<int>::iterator i = Sigma.begin(); i != Sigma.end(); i++)
		{
			if (*i == 'ュ') continue;
			cout << *i;
			makeDFA_Delta(DFA_Q[idx], *i);
		}
	}

	makeDFA_F();
}

int GroupNumber(DfaState state)
{
	for (int i = 0; i < Group.size(); i++)
	{
		if (find(Group[i].begin(), Group[i].end(), state) != Group[i].end())
		{
			return i;
		}
	}
}

vector<R_DfaState> Grouping(R_DfaState group, int sigma)
{
	vector<R_DfaState> temp;
	vector<State> criteria = TransitionResult(group[0], sigma);

	int criteria_Num = GroupNumber(criteria);

	vector<DfaState> first, second;
	for (int j = 0; j < group.size(); j++)
	{
		if (GroupNumber(TransitionResult(group[j], sigma)) == criteria_Num)
			first.push_back(group[j]);
		else second.push_back(group[j]);
	}
	temp.push_back(first);
	if (!second.empty())
	{
		vector<R_DfaState>sGroup = Grouping(second, sigma);
		temp.insert(temp.end(), sGroup.begin(), sGroup.end());
	}
	return temp;

}


void DFAtoReduceDFA()
{

	for (vector<DfaState>::iterator it = DFA_Q.begin(); it != DFA_Q.end(); it++)
	{
		if (find(DFA_F.begin(), DFA_F.end(), *it) != DFA_F.end())
			Group[0].push_back(*it);

		else Group[1].push_back(*it);
	}

	vector<R_DfaState> temp;

	for (vector<int>::iterator sgit = Sigma.begin(); sgit != Sigma.end(); sgit++)
	{
		for (int idx = 0; idx < Group.size(); idx++)
		{
			vector<R_DfaState> r = Grouping(Group[idx], *sgit);
			temp.insert(temp.end(), r.begin(), r.end());
		}
		if (temp.size() > Group.size())
		{
			Group = temp;
			temp.clear();
			sgit = Sigma.begin();
		}
		temp.clear();
	}

	ReducedDFA_Q = Group;

	for (int i = 0; i < ReducedDFA_Q.size(); i++)
	{
		bool start_check = false;

		if (!start_check && (find(ReducedDFA_Q[i].begin(), ReducedDFA_Q[i].end(), DFA_startState) != ReducedDFA_Q[i].end()))
		{
			ReducedDFA_startState = ReducedDFA_Q[i];
			start_check = true;
		}

		for (vector<DfaState>::iterator dit = DFA_F.begin(); dit != DFA_F.end(); dit++)
		{
			if (find(ReducedDFA_Q[i].begin(), ReducedDFA_Q[i].end(), *dit) != ReducedDFA_Q[i].end())
				ReducedDFA_F.push_back(ReducedDFA_Q[i]);
		}

		for (int j = 0; j < Sigma.size(); j++)
		{
			Reduced_DFA_Delta.push_back(
				Transition_Reduced_DFA(
					ReducedDFA_Q[i], Sigma[j], TransitionResult(ReducedDFA_Q[i][0], Sigma[j])
				)
			);
		}
	}
}

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

	DFA_Q = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"} };
	/*Sigma = { 'a','b','c', 'ュ' };*/\
		Sigma = { 'a','b' };


	DFA_Delta = {
		Transition_DFA("A", 'a', "F"),
		Transition_DFA("A", 'b', "B"),
		Transition_DFA("B", 'a', "E"),
		Transition_DFA("B", 'b', "D"),
		Transition_DFA("C", 'a', "C"),
		Transition_DFA("C", 'b', "F"),
		Transition_DFA("D", 'a', "D"),
		Transition_DFA("D", 'b', "A"),
		Transition_DFA("E", 'a', "B"),
		Transition_DFA("E", 'b', "C"),
		Transition_DFA("F", 'a', "A"),
		Transition_DFA("F", 'b', "E"),
	};

	DFA_startState = { "A" };

	DFA_F = { {"A"}, {"F"} };

	DFAtoReduceDFA();

}