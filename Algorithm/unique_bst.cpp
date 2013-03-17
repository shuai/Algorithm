//
//  unique_bst.cpp
//  Algorithm
//
//  Created by Shuai on 3/16/13.
//
//

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n < 1)
            return 0;
        
        int num[n+1];
        num[0] = num[1] = 1;
        
        for (int i=2; i<=n; i++) {
            int result = 0;
            for (int split=0; split<i/2; split++)
                result += num[split]*num[i-split-1];
            result <<= 1;
            if (i&1)
                result += num[i>>1]*num[i>>1];
            num[i] = result;
        }
        return num[n];
    }
};
