//
//  priority_queue.cpp
//  Algorithm
//
//  Created by  on 7/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

#include <queue>

#include "priority_queue.h"

void test_min_heap()
{
    MinHeap<int> heap;
    
    heap.add(10);
    
    cout << "extract 1 number heap " << heap.extract_min() << endl;
    
    heap.add(20);
    heap.add(1);
    heap.add(5);
    heap.add(7);
    heap.add(3);
    heap.add(15);
    heap.extract_min();
    
    
    cout << "extrac all from heap";
    while (!heap.empty())
    {
        cout << " " << heap.extract_min();
    }
    cout << endl;
    
}
