//
//  N-queen-2.cpp
//  Algorithm
//
//  Created by Shuai on 11/1/12.
//
//

class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0)
            return 0;
        
        return solve(0, 0, 0, n, (1<<n)-1);
    }
    
    int solve(unsigned left, unsigned middle, unsigned right, int n, int mask) {
        if (n == 0)
            return 1;
        
        int count = 0;
        unsigned m = ~(left | middle | right)&mask;
        while (m) {
            unsigned bit = m;
            m &= m - 1;
            bit -= m;
            
            count += solve((left | bit) << 1, middle | bit, (right | bit) >> 1, n-1, mask);
        }
        return count;
    }
};