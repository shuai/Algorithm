//
//  sell_stock_1.cpp
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
        
        int low = prices.front(), profit = 0;
        for (int price : prices) {
            if (price < low)
                low = price;
            else
                profit = max(profit, price-low);
        }
        return profit;
    }
};