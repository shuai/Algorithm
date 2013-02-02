//
//  subset.cpp
//  Algorithm
//
//  Created by Shuai on 2/2/13.
//
//

#include "include.h"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > result;
        result.push_back(vector<int>());
        sort(S.begin(), S.end());
        subsetWithDup(result, S, 0);
        return result;
    }
    
    void subsetWithDup(vector<vector<int> >& ret, vector<int>& S, int index) {
        
        if (index == S.size())
            return;
        
        int pos = index;
        while (pos+1 < S.size() && S[pos+1] == S[pos])
            pos++;
        
        subsetWithDup(ret, S, pos+1);
        int size = ret.size();
        ret.reserve(ret.size()*(pos-index+2));
        for (int i=1; i<=pos-index+1; i++) {
            vector<vector<int> >::iterator start = ret.begin();
            int count = 0;
            while (count++ < size) {                
                vector<int> v(i, S[index]);
                copy(start->begin(), start->end(), back_inserter(v));
                ret.push_back(v);
                start++;
            }
        }
    }
};

void test_subset() {
    Solution s;
    vector<int> S = {1, 2};
    auto result = s.subsetsWithDup(S);
}