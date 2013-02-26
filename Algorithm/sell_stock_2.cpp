//
//  sell_stock_2.cpp
//  Algorithm
//
//  Created by Shuai on 2/26/13.
//
//

#include "include.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (prices.empty())
            return 0;
        
        int profit = 0, prev = prices.front();
        for (int price : prices) {
            if (price > prev)
                profit += price-prev;
            prev = price;
        }
        return profit;
    }
};