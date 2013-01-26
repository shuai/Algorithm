//
//  permutation.cpp
//  Algorithm
//
//  Created by Shuai on 9/10/12.
//
//

#include <vector>
#include <iostream>

using namespace std;


void print_all(int left, int right, vector<bool>& exist)
{
    if (!left && !right) {
        for (int i=0; i<exist.size(); i++) {
            cout << (exist[i] ? '(' : ')');
        }
        cout << endl;
        return;
    }
    
    if (right > left) {
        exist.push_back(false);
        print_all(left, right-1, exist);
        exist.pop_back();
    }
    
    if (left) {
        exist.push_back(true);
        print_all(left-1, right, exist);
        exist.pop_back();
    }
}

void test_print_all()
{
    vector<bool> exist;
    
    print_all(3, 3, exist);
}