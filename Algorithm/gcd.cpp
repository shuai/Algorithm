//
//  gcd.cpp
//  Algorithm
//
//  Created by  on 7/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned gcd(unsigned x, unsigned y)
{
    unsigned factor = 1;
    
    while (true) {
        if (x == y)
            break;
        
        if (x & 1 && y & 1)
        {
            if (x>y)
                x -= y;
            else {
                y -= x;
            }
        }
        else if (!(x&1) && !(y&1))
        {
            factor*=2;
            x = x >> 1;
            y = y >> 1;
        }
        else if (x&1)
        {
            y >>= 1;
        }
        else
        {
            x >>= 1;
        }
    }
    
    return x * factor;
}

void test_gcd()
{    
    cout << "gcd of 100 && 25: " << gcd(100, 25) << endl;
    cout << "gcd of 100 && 24: " << gcd(100, 24) << endl;
    cout << "gcd of 100 && 20: " << gcd(100, 20) << endl;
    cout << "gcd of 99 && 22: " << gcd(99, 22) << endl;
    cout << "gcd of 145 && 25: " << gcd(145, 25) << endl;
    
}
