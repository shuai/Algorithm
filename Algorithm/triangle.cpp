//
//  triangle.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (triangle.empty())
            return 0;
        
        vector<int> last(1, triangle[0][0]), current;
        for (int layer=1; layer<triangle.size(); layer++) {
            current.resize(layer+1);
            for (int pos = 1; pos < layer; pos++)
                current[pos] = triangle[layer][pos] + min(last[pos-1], last[pos]);
            current.front() = triangle[layer].front() + last.front();
            current.back() = triangle[layer].back() + last.back();
            last.swap(current);
        }
        return *min_element(last.begin(), last.end());
    }
};
