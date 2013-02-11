//
//  test.h
//  Algorithm
//
//  Created by Shuai on 8/12/12.
//
//

#ifndef __Algorithm__test__
#define __Algorithm__test__

#include <iostream>
#include <vector>
#include "include.h"

using namespace std;

ListNode* build_list();

ListNode* build_circular_list();

TreeNode* build_tree();

void build_random_array(unsigned size, unsigned max, vector<int>& array);

void build_dag(vector<bool>& array);

void build_weighted_dag(vector<vector<int> >& array);

void build_random_weighted_graph(unsigned v, vector<unsigned>& array);




template <class T>
void print_array(vector<T>& array)
{
    if (array.empty())
        cout << "Empty array" << endl;
    else
    {
        cout << "Array:";
        for (int i=0; i<array.size(); i++) {
            cout << " " << array[i];
        }
        cout << endl;
    }
}

template <class T>
void print_matrix(T& array)
{
    if (array.empty())
        cout << "Empty matrix" << endl;
    else
    {
        for (unsigned i=0; i<array.size(); i++) {
            for (unsigned j=0; j<array[i].size(); j++) {
                if (array[i][j] == INT_MAX)
                    cout << "*";
                else
                    cout << array[i][j];
                
                cout << "\t";
            }
            cout << endl;
        }
    }
    cout << "--------------------" << endl;
}

#endif /* defined(__Algorithm__test__) */
