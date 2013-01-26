//
//  sort.cpp
//  Algorithm
//
//  Created by Shuai on 9/11/12.
//
//
#include <iostream>
using namespace std;

void merge(int* a, unsigned countA, int*b, unsigned countB)
{
    int* ptr = a+countA+countB-1;
    
    while (countB) {
        if (!countA || b[countB-1] > a[countA-1])
        {
            *ptr = b[countB-1];
            countB --;
        }
        else
        {
            *ptr = a[countA-1];
            countA --;
        }
        ptr --;
    }
}

void test_merge_array()
{
    int a[10] = {1,2,3};
    int b[] = {-1,0,1,1,2,3,4};
    merge(a, 3, b, sizeof(b)/(sizeof(int)));
    for (int i=0; i<10; i++) {
        cout << a[i];
    }
    cout << endl;
    
}