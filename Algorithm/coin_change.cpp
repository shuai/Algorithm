//
//  coin_change.cpp
//  Algorithm
//
//  Created by Shuai on 8/23/12.
//
//

//Problems 16-1: Coin changing
//
//Consider the problem of making change for n cents using the fewest number of coins. Assume that each coin's value is an integer.
//Give an O(nk)-time algorithm that makes change for any set of k different coin denominations, assuming that one of the coins is a penny.

#include <vector>
#include <cassert>
#include "test.h"
using namespace std;


void split_integer(unsigned integer, const vector<unsigned>& factors, vector<unsigned>& counter)
{
    vector<unsigned> p, c;
    p.resize(integer+1);
    c.resize(integer+1);
    counter.resize(factors.size());
    p[0] = 0;
    c[0] = 0;
    
    for (unsigned i=1; i<=integer; i++) {
        unsigned num = ~0;
        unsigned choice = 0;
        for (unsigned j=0; j<factors.size(); j++) {
            if (factors[j] <= i && p[i-factors[j]] + 1 < num)
            {
                num = p[i-factors[j]] + 1;
                choice = j;
            }
        }
        
        assert(num != ~0);
        p[i] = num;
        c[i] = choice;
    }
    
    while (integer) {
        counter[c[integer]] ++;
        integer = integer - factors[c[integer]];
    }
}

void test_split_integer()
{
    unsigned integer = 65;
    vector<unsigned> factors;
    factors.push_back(50);
    factors.push_back(20);
    factors.push_back(10);
    factors.push_back(2);
    factors.push_back(1);
    
    vector<unsigned> output;
    split_integer(integer, factors, output);
    
    cout << "Split integer:" << integer << endl;
    cout << "Factor: ";
    print_array(factors);
    
    cout << "Result: ";
    for (unsigned i=0; i<output.size(); i++) {
        if (output[i])
            cout << factors[i] << "*" << output[i] << " ";
    }
    cout << endl;
}