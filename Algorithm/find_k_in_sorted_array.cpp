//
//  find_k_in_sorted_array.cpp
//  Algorithm
//
//  Created by Shuai on 2/11/13.
//
//

#include "include.h"

enum FindType {
    Lesser,
    LesserEqual,
    Equal,
    GreaterEqual,
    Greater
};

class Iterator {
public:
    Iterator(const vector<int>& array)
    :array(array)
    {
        assert(array.size());
        ascending = array.front() <= array.back();
        offset = ascending ? 0 : array.size() - 1;
    }
    
    bool can_step(bool forward) {
        int new_offset = offset + ascending == forward ? 1 : -1;
        return 0 <= new_offset && new_offset < array.size();
    }
    
    Iterator& step(bool forward) {
        offset += ascending == forward ? 1 : -1;
        assert(valid());
        return *this;
    }
    
    int operator *() { return array[offset]; }
    bool valid() { return index() != -1; }
    int index() { return 0 <= offset && offset < array.size() ? offset : -1; }
private:
    const vector<int>& array;
    bool ascending;
    int offset;
};

Iterator find(const vector<int>& array, int k) {
    Iterator it(array);
    while (it.can_step(true) && *it < k)
        it.step(true);
}

int find(const vector<int>& array, int k, FindType t) {
    Iterator it = find(array, k);
    if (k == *it && (t == Equal || t == LesserEqual || t == GreaterEqual))
        return it.index();
    
    if (t == Lesser || t == LesserEqual)
        return *it < k ? it.index() : (it.can_step(false) ? it.step(false).index() : -1);
    if (t == Greater || t == GreaterEqual)
        return *it > k ? it.index() : (it.can_step(true) ? it.step(true).index() : -1);
    return -1;
}