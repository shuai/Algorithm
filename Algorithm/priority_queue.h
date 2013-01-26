//
//  priority_queue.h
//  Algorithm
//
//  Created by Shuai on 9/17/12.
//
//

#ifndef Algorithm_priority_queue_h
#define Algorithm_priority_queue_h

#include <vector>
#include <cassert>
#include <map>
#include <algorithm>
using namespace std;

template <class T, class Comp = less<T> >
class MinHeap
{
public:
    MinHeap()
    {
    }
    
    T extract_min()
    {
        assert(array.size());
        
        T min = array[0];
        
        swap(array[0], array[array.size()-1]);
        array.pop_back();
        heapify(0);
        
        return min;
    }
    
    // return index
    unsigned add(T item)
    {
        array.push_back(item);
        return heapify(array.size() - 1);
    }
    
    // return index
    unsigned update(unsigned index, const T& newvalue)
    {
        assert(array.size() > index);
        array[index] = newvalue;
        return heapify(index);
    }
    
    bool empty() { return array.empty(); }
private:
    
    unsigned heapify(unsigned index)
    {
        unsigned minimum = index;
        
        while (true)
        {
            if (left(index) < array.size())
                minimum = Comp()(array[left(index)], array[index]) ? left(index) : index;
            
            if (right(index) < array.size() && Comp()(array[right(index)], array[minimum]))
                minimum = right(index);
            
            if (minimum == index)
                break;
            
            swap(array[index], array[minimum]);
            index = minimum;
        }
        
        while(index)
        {
            if (Comp()(array[index], array[parent(index)]))
                swap(array[index], array[parent(index)]);
            else
                break;
            index = parent(index);
        }
        return index;

    }
    unsigned left(unsigned index)
    {
        return index*2 + 1;
    }
    unsigned right(unsigned index)
    {
        return left(index) + 1;
    }
    unsigned parent(unsigned index)
    {
        return (index-1)/2;
    }
        
    vector<T> array;
};

#endif
