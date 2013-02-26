//
//  sell_stock_3.cpp
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
        
        int sell[prices.size()], buy[prices.size()];
        
        int low = prices.front(), profit = 0;
        for (int i=0; i<prices.size(); i++) {
            if (prices[i] < low)
                low = prices[i];
            else
                profit = max(profit, prices[i]-low);
            sell[i] = profit;
        }
        
        profit = 0;
        int high = prices.back();
        for (int i=prices.size()-1; i>=0; i--) {
            if (prices[i] > high)
                high = prices[i];
            else
                profit = max(profit, high-prices[i]);
            buy[i] = profit;
        }
        
        profit = max(sell[prices.size()-1], buy[0]);
        for (int i=0; i<prices.size()-1; i++)
            profit = max(profit, sell[i] + buy[i+1]);
        return profit;
    }
};