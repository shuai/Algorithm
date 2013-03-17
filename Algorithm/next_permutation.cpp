//
//  next_permutation.cpp
//  Algorithm
//
//  Created by Shuai on 3/17/13.
//
//

#include "include.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (num.size() < 2)
            return;
        
        int exchange=num.size()-2;
        for (; exchange>=0; exchange--)
            if (num[exchange] < num[exchange+1])
                break;
        
        if (exchange != -1)
            for (int i=exchange; i<num.size(); i++)
                if (num[i] > num[exchange] && (i == num.size()-1 || num[i+1] <= num[exchange])) {
                    swap(num[i], num[exchange]);
                    break;
                }
        
        reverse(num.begin()+exchange+1, num.end());
    }
};
