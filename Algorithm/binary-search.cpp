//
//  binary-search.cpp
//  Algorithm
//
//  Created by  on 7/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;

int bisearch(const int* input, const int size, int key);

void test_bisearch()
{
    int array[] = {1,5,6,8,9,12,15, 16,18};
    int key = 15;
    cout << "bisearch array, key: " << key;
    if (bisearch(array, sizeof(array)/sizeof(array[0]), key) != -1)
        cout << " found";
    else {
        cout << " not found";
    }
    cout << endl;
}

int bisearch(const int* input, const int size, int key)
{
    if (!input || size < 1)
        return -1;
    
    int min = 0;
    int max = size;
    int middle = 0;
    
    while (min < max)
    {
        middle = min + (max - min)/2;
        if (input[middle] == key)
            return middle;
        else if (input[middle] > key)
            max = middle;
        else {
            min = middle + 1;
        }
    }
    
    assert(middle >= 0 && middle < size);
    if (input[middle] == key)
        return middle;
    return -1;
}