//
//  knapsack.cpp
//  Algorithm
//
//  Created by Shuai on 8/19/12.
//
//

//Exercises 16.2-2
//Give a dynamic-programming solution to the 0-1 knapsack problem that runs in O(n W) time,
//where n is number of items and W is the maximum weight of items that the thief can put in his knapsack.

#include <vector>
#include <iostream>

using namespace std;

void knapsack01weighted(const vector<pair<unsigned, unsigned> >& items, unsigned capacity)
{
    unsigned c[capacity+1][items.size()+1];
    
    for (size_t i=0; i<items.size(); i++) {
        c[0][i] = 0;
    }
    
    for (size_t i=1; i<=capacity; i++) {
        c[i][0] = 0;
        for (size_t j=1; j<=items.size(); j++) {
            unsigned weight = items[j-1].first;
            unsigned value = items[j-1].second;
            
            unsigned max = c[i][j-1];
            if (weight <= i && c[i-weight][j-1] + value > max)
            {
                max = c[i-weight][j-1] + value;
            }
            c[i][j] = max;
        }
    }
    
    cout << "Max value: " << c[capacity][items.size()] << endl;
    unsigned i = capacity, j = items.size();
    while (c[i][j]) {
        unsigned weight = items[j-1].first;
        unsigned value = items[j-1].second;

        if (c[i][j] == c[i-weight][j-1] + value)
        {
            cout << "Weight: " << weight << " Value: " << value << endl;
            i = i-weight;
            j --;
        }
        else
            j --;
    }
}


void test_knapsack()
{
    vector<pair<unsigned, unsigned> > items;
    
    items.push_back(make_pair(10, 60));
    items.push_back(make_pair(20, 100));
    items.push_back(make_pair(30, 120));

    knapsack01weighted(items, 50);
}