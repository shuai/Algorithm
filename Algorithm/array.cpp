//
//  array.cpp
//  Algorithm
//
//  Created by Shuai on 9/24/12.
//
//

// 1,2,3,a,b,c -> 1,a,2,b,3,c

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <memory>


#include "test.h"

using namespace std;


bool test_array_bitonic(vector<int>& array)
{
    if (array.size() < 3) {
        return false;
    }
    bool valley = false, valleybeforepeek = false, peek = false;
    
    for (int i=1; i<array.size()-1; i++) {
        if (array[i] > array[i-1] && array[i] > array[i+1]) {
            if (peek) {
                return false;
            }
            peek = true;
        }
        else if(array[i] < array[i-1] && array[i] < array[i+1]) {
            if (valley) {
                return false;
            }
            valley = true;
            valleybeforepeek = !peek;
        }
    }

    if (valley && peek)
    {
        return valleybeforepeek ? array[0] <= array.back() : array[0] >= array.back();
    }

    return valley || peek;
}

void find_triplet(vector<int>& array1, vector<int>& array2, vector<int>& array3, unsigned& number1, unsigned& number2, unsigned& number3)
{
    unsigned index1 = 0, index2 = 0, index3 = 0;
    
    int range = INT_MAX;
    
    while (index1 < array1.size()) {
        int current_min = min(min(array1[index1], array2[index2]), array3[index3]);
        int current_max = max(max(array1[index1], array2[index2]), array3[index3]);
        if (current_max - current_min < range) {
            range = current_max - current_min;
            number1 = array1[index1];
            number2 = array2[index2];
            number3 = array3[index3];
        }
        
        if (array3[index3] < array1[index1] || array2[index2] < array1[index1]) {
            if (array3[index3] < array2[index2]) {
                if (index3 == array3.size()) {
                    return;
                }
                index3++;
            }
            else
            {
                if (index2 == array2.size()) {
                    return;
                }
                index2 ++;
            }
        }
        else
        {
            if (index1 == array1.size()) {
                return;
            }
            
            index1 ++;
        }
        
    }
}

//1、从一列数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的
void make_array_bitonic(vector<int>& array)
{
    // calculate increasing sequence
    unsigned increasing[array.size()];
    unsigned max[array.size()];

    for (size_t i=0; i<array.size(); i++) {
        max[i] = UINT_MAX;
    }
    
    for (size_t i=0; i<array.size(); i++) {
        unsigned low = 0, high = (unsigned)i;
        while (low < high) {
            unsigned middle = (low+high)/2;
            if (max[middle] < array[i]) {
                low = middle+1;
            }
            else if (max[middle] >= array[i]){
                high = middle;
            }
        }
        increasing[i] = low + 1;
        if (array[i] < max[low]) {
            max[low] = array[i];
        }
    }
}

bool even_partition(const vector<unsigned>& v)
{
    unsigned sum = 0;
    for (size_t i=0; i<v.size(); i++) {
        sum += v[i];
    }
    
    bool t[sum/2+1][v.size()+1];
    for (size_t i=0; i<v.size()+1; i++) {
        t[0][i] = true;
    }
    for (size_t i=1; i<sum/2+1; i++) {
        t[i][0] = false;
    }
    
    for (size_t i=1; i<sum/2+1; i++) {
        for (size_t j=1; j<v.size()+1; j++) {
            t[i][j] = t[i][j-1] || (v[j-1] <= i && t[i-v[j-1]][j-1]);
        }
    }
    return  t[sum/2][v.size()];
}

// 2n个元素，分成2组，要和最接近
void partition2(const vector<unsigned>& v, vector<unsigned>& array1)
{
    unsigned sum = 0;
    for (size_t i=0; i<v.size(); i++) {
        sum += v[i];
    }
    
    // initialize for sub problem of size 0
    bool table[v.size()+1][v.size()+1][sum/2+1];
    for (size_t j=1; j<=sum/2; j++) {
        table[0][0][j] = false;
    }
    
    for (size_t i=0; i<=v.size(); i++) {
        for (size_t j=1; j<=sum/2; j++) {
            table[i][0][j] = false;
        }
    }
    
    // initialize for sub problem that sums to 0
    for (size_t i=0; i<=v.size(); i++) {
        table[i][0][0] = true;
    }
    
    for (size_t i=1; i<=v.size(); i++) {
        for (size_t j=1; j<=i; j++) {
            if (j == i) {
                for (size_t k=0; k<=sum/2; k++) {
                    table[i][j][k] = v[i-1] <= k && table[i-1][j-1][k-v[i-1]];
                }
            }
            else {
                for (size_t k=0; k<=sum/2; k++) {
                    table[i][j][k] = (table[i-1][j][k]) || (v[i-1] <= k && table[i-1][j-1][k-v[i-1]]);
                }
            }
        }
    }
    
    unsigned max_sum = sum/2, size = v.size(), subset = v.size()/2;
    while (!table[v.size()][v.size()/2][max_sum]) {
        max_sum --;
    }
    
    while (subset) {
        if (size-1 >= subset && table[size-1][subset][max_sum]) {
        }
        else {
            max_sum -= v[size-1];
            subset --;
            assert(table[size-1][subset][max_sum]);
            array1.push_back(v[size-1]);
        }
        size --;
    }
}

bool search_set(vector<unsigned>& v, vector<bool>& flag, unsigned offset, unsigned left, unsigned m, unsigned sum)
{
    if (left == 0)
    {
        left = sum;
        m--;
    }
    
    for (unsigned i=offset; i<flag.size(); i++) {
        if (!flag[i]) {
            if (v[i] > left || (i>offset && !flag[i-1]))
                continue;
            else if (v[i] == left)
            {
                flag[i] = true;
                if (m == 0) {
                    cout << v[i] << " ";
                    return true;
                }
                else
                {
                    if (search_set(v, flag, 0, 0, m, sum))
                    {
                        cout << endl << v[i] << " ";
                        return true;
                    }
                    else {
                        flag[i] = false;
                        return false;
                    }
                }
            }
            else
            {
                flag[i] = true;
                if (search_set(v, flag, i+1, left-v[i], m, sum))
                {
                    cout << v[i] << " ";
                    return true;
                }
                else if (left == sum) {
                    flag[i] = false;
                    return false;
                }
                else {
                    flag[i] = false;
                    continue;
                }
            }
        }
    }
    
    return false;
}

// n个元素，分成m组，要求每组和相同，求m最大值
unsigned split_set(vector<unsigned>& v)
{
    unsigned sum = 0;
    for (size_t i=0; i<v.size(); i++) {
        sum += v[i];
    }
    
    unsigned max = *max_element(v.begin(), v.end());
    
    sort(v.rbegin(), v.rend());
    
    unsigned m = v.size();
    vector<bool> flag;
    flag.resize(m);
    while (m) {
        if (sum%m == 0 && sum/m >= max) {
            if (search_set(v, flag, 0, 0, m, sum/m)) {
                return m;
            }
        }
        m--;
    }
    return 0;
}

void test_split_set()
{
    for (size_t i=0; i<1; i++) {
        unsigned count = 10240;
        vector<unsigned> v;
        for (size_t j=0; j<count; j++) {
            v.push_back(rand()%4);
            //v.push_back(1);
        }
        
//        v.clear();
//        v.push_back(9);
//        v.push_back(9);
//        v.push_back(12);
        
        print_array(v);
        unsigned mm = split_set(v);
        cout << endl << "maximum m: " << mm << endl;
    }
}

void test_even_partition()
{
    vector<unsigned> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);
    
    cout << even_partition(v) << endl;
}

void test_partition2()
{
    vector<unsigned> v, v1;
//    v.push_back(1);
//    v.push_back(4);
//    v.push_back(0);
//    v.push_back(4);
//    v.push_back(9);
//    v.push_back(8);
    unsigned count = 2*(rand()%5 + 5);
    for (int i=0; i<count; i++) {
        v.push_back(rand()%10);
    }
    
    partition2(v, v1);
    
    print_array(v);
    cout << "->" << endl;
    print_array(v1);

}

void test_array1()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(3);
    test.push_back(-1);
    test.push_back(1);

    cout << "test array bitonic: " << test_array_bitonic(test) << endl;

}



void test_array2()
{
    vector<int> array1, array2, array3;
    build_random_array(10, 100, array1);
    build_random_array(10, 100, array2);
    build_random_array(10, 100, array3);
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    sort(array3.begin(), array3.end());

    
    print_array(array1);
    print_array(array2);
    print_array(array3);

    unsigned num1, num2, num3;
    find_triplet(array1, array2, array3, num1, num2, num3);
    cout << "Triplet: " << num1 << " " << num2 << " " << num3 << endl;
}


// search rotated array
int search_rotated(int* array, unsigned count, int key)
{
    unsigned low = 0, high = count;
    while (low < high) {
        unsigned middle = (low+high)/2;
        if (array[middle] == key) {
            return middle;
        }
        
        if (array[middle] > array[high-1]) {
            if (key > array[middle] || key <= array[high-1])
                low = middle+1;
            else
                high = middle;
        }
        else if (key < array[middle] || key > array[high-1]) {
            high = middle;
        }
        else
            low = middle + 1;
    }
    return -1;
}

void test_search_rotated()
{
    int a[4];
    a[0] = 10;
    a[1] = 1;
    a[2] = 1;
    a[3] = 5;
    int index = search_rotated(a, 4, 5);
    
    
    const int SIZE = 30;
    int array[SIZE];
    for (size_t i=0; i<100; i++) {
        for (size_t j=0; j<SIZE; j++) {
            array[j] = rand()%20;
        }
        
        sort(array, array+SIZE);
        rotate(array, array+rand()%SIZE, array+SIZE);
        
        if (SIZE > 1 && array[0] == array[SIZE-1]) {
            continue;
        }
        
        for (size_t j=0; j<SIZE; j++) {
            cout << array[j] << " " ;
        }
        cout << endl;
        
        for (size_t j=0; j<SIZE; j++) {
            int index = search_rotated(array, SIZE, array[j]);
            if (index == -1 || array[index] != array[j]) {
                cout << "search failed: " << array[j] << endl;
                return;
            }
        }
        
        for (size_t j=0; j<100; j++) {
            int key = rand()%30;
            int* index1 = find(array, array+SIZE, key);
            int index2 = search_rotated(array, SIZE, key);
            if ((index1 == array+SIZE) != (index2 == -1)) {
                cout << "search failed2: " << key << endl;
                return;
            }
        }
    }
}

void find_palindrome_brute(const char* str, unsigned& start, unsigned& end)
{
    if (!*str) {
        start = end = 0;
        return;
    }
    
    unsigned size = 2*strlen(str)-1;
    unsigned i=0, max=0;
    while (i<size) {
        unsigned len = 0;
        int left = i/2;
        int right = (i+1)/2;
        while (left >= 0 && right < size && str[left] == str[right]) {
            len ++;
            left --;
            right ++;
        }
        
        if (len > max || (len == max && (i&1))) {
            max = len;
            start = left + 1;
            end = right;
        }
        i++;
    }
}

string longestPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.empty())
        return "";
    
    unsigned lpsize = 2*s.size() - 1;
    int lp[lpsize];
    memset(lp, 0, sizeof(lp));
    
    int center = 0;
    while (center < lpsize) {
        if (lp[center] > 0)
        {
            center ++;
            continue;
        }
        
        if (lp[center] < 0)
            lp[center] = -lp[center];
        
        // expand the current palindrome
        while (true) {
            int left = center - lp[center];
            int right = center + lp[center];
            if (left >= 0 && right < lpsize && ((left&1) || s[left/2] == s[right/2]))
                lp[center]++;
            else
                break;
        }
        
        // walk backwards and fill the right part of the current palindrome in lp array
        unsigned max_offset = lp[center]-1;
        assert(center >= max_offset && center + max_offset < lpsize);
        unsigned offset = 1;
        while (offset <= max_offset) {
            unsigned left_bound = center - offset + 1 - lp[center-offset];
            if (left_bound == center - max_offset) {
                lp[center+offset] = -lp[center-offset];
            }
            else if (left_bound > center - max_offset)
                lp[center+offset] = lp[center-offset];
            else
                lp[center+offset] = lp[center] - offset;
            
            offset++;
        }
        
        center ++;
    }
    
    int max = -1;
    unsigned i = 0, start = 0, end = 0;
    while (i < lpsize) {
        if (lp[i] >= max) {
            max = lp[i];
            unsigned s = (i + 2 - lp[i])/2;
            unsigned e = (i + lp[i] - 1)/2 + 1;
            if (e-s > end-start) {
                start = s;
                end = e;
            }
        }
        i++;
    }
    
    return string(s, start, end-start);
}

void test_palindrome()
{

    for (int i=0; i<100; i++) {
        unsigned count = rand()%100;
        char str[count+1];
        str[count] = 0;
        for (int j=0; j<count; j++) {
            str[j] = 'a' + rand()%2;
        }
        
        cout << str << endl;
        string r1,r2;
        
        unsigned start, end;
        find_palindrome_brute(str, start, end);
        r1.assign(str+start, str+end);

        string palindrome = longestPalindrome("ccc");
        
        
        if (r1.size() != r2.size()) {
            cout << "!!!!!!!!" << endl;
        }
        cout << "1: " << r1 << endl;
        cout << "2: " << r2 << endl;
        
    }
    
//    const char* str = "dbcbceec";
//    string r1;
//    unsigned start, end;
//    find_palindrome(str, start, end);
//    r1.assign(str+start, str+end);
//    cout << r1 << endl;
}
