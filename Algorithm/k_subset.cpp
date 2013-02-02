//
//  k_subset.cpp
//  Algorithm
//
//  Created by Shuai on 1/31/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        
        if (n == 0)
            return result;
        
        int comb[n][k];
        for (int i=0; i<n; i++)
            comb[i][0] = 1;
        
        for (int i=1; i<k; i++) {
            comb[i][i] = 1;
            for (int row=i+1; row<n; row++)
                comb[row][i] = comb[row-1][i]*row/(row-i);
        }
        
        int count = comb[n-1][k-1]*n/k;
        
        for (int i=0; i<count; i++) {
            int num=k, rank=i, current=1;
            vector<int> val;
            while (num) {
                if (rank < comb[n-current][num-1]) {
                    val.push_back(current);
                    num--;
                    current++;
                } else {
                    rank -= comb[n-current][num-1];
                    current++;
                }
            }
            result.push_back(val);
        }
        
        return result;
    }
};

void test_combine() {
    Solution s;
    vector<vector<int> > result = s.combine(13, 2);
    for (auto array : result) {
        for (auto element : array) {
            cout << element << " ";
        }
        cout << endl;        
    }
}