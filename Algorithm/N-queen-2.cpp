//
//  N-queen-2.cpp
//  Algorithm
//
//  Created by Shuai on 11/1/12.
//
//

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long MASK_T;

MASK_T MASK;
unsigned N;
unsigned Nqueen(vector<MASK_T> queens, MASK_T left, MASK_T middle, MASK_T right)
{
    if (queens.size() == N)
        return 1;
    
    queens.push_back(0);

    unsigned count = 0;
    MASK_T bitmap = MASK & ~(left | middle | right);
    while (bitmap) {
        MASK_T bit = bitmap&(-bitmap);
        bitmap ^= bit;
        queens.back() = bit;
        count += Nqueen(queens, (bit | left) << 1, middle | bit, (right | bit) >> 1);
    }
    
    queens.pop_back();
    return count;
}

void test_n_queen()
{
    vector<MASK_T> result;
    for (int i=1; i<15; i++) {
        N = i;
        MASK = (1 << i) - 1;
        cout << "Nqueen " << i << " -> " << Nqueen(result, 0, 0, 0) << endl;
    }
}