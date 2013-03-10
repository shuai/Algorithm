//
//  random_variable.cpp
//  Algorithm
//
//  Created by Shuai on 3/6/13.
//
//

#include "include.h"

// Generate a set of random variable from a single big random number
// An*N! + A(n-1)*(N-1)! + .. + A2*2! + A1
void generate(vector<int>& output, int n) {
    int factorial = 1;
    for (int i=1; i<=n; i++) {
        factorial *= i;
    }
    
    int num = rand()%factorial;
    int divisor = 2;
    for (int i=0; i<n; i++) {
        output.push_back(num%divisor);
        num /= divisor;
        divisor ++;
    }
}

void test_random() {
    for (int k=0; k<100; k++) {
        int n=0;
        vector<int> output;
        generate(output, n);
        for (int i=0; i<n; i++) {
            cout << output[1] << " (" << i+1 << ") ";
        }
        cout << endl;
    }
}
