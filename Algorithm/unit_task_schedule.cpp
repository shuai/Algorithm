//
//  unit_task_schedule.cpp
//  Algorithm
//
//  Created by Shuai on 8/23/12.
//
//

#include <vector>

using namespace std;

//Problems 16-4: Scheduling variations
//
//Consider the following algorithm for the problem from Section 16.5 of scheduling unit-time tasks with deadlines and penalties. Let all n time slots be initially empty, where time slot i is the unit-length slot of time that finishes at time i. We consider the tasks in order of monotonically decreasing penalty. When considering task aj , if there exists a time slot at or before aj 's deadline dj that is still empty, assign aj to the latest such slot, filling it. If there is no such slot, assign task aj to the latest of the as yet unfilled slots.
//Argue that this algorithm always gives an optimal answer.
//Use the fast disjoint-set forest presented in Section 21.3 to implement the algorithm efficiently. Assume that the set of input tasks has already been sorted into monotonically decreasing order by penalty. Analyze the running time of your implementation.

struct node
{
    int next;
    int prev;
    unsigned value;
};

void schedule(vector<pair<unsigned, unsigned> >& tasks, vector<unsigned>& output)
{

}