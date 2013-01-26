//
//  LIS.cpp
//  Algorithm
//
//  Created by Shuai on 8/12/12.
//
//

#include "test.h"
#include <vector>
#include <algorithm>

using namespace std;


void lis_brute_force(const vector<int>& array, vector<int>& result)
{
    result.clear();
    if (!array.size())
        return;
    
    unsigned lis[array.size()];
    int ptr[array.size()];
    for (int i=0; i<array.size(); i++) {
        lis[i] = 1;
        ptr[i] = -1;
        for (int j=0; j<i; j++) {
            if (array[i] > array[j] && lis[j] >= lis[i])
            {
                lis[i] = lis[j]+1;
                ptr[i] = j;
            }
        }
    }
    
    int max_i = max_element(lis, lis+array.size()) - lis;
    
    while (max_i != -1) {
        result.insert(result.begin(), array[max_i]);
        max_i = ptr[max_i];
    }
}

void lis_dp(const vector<int>& array, vector<int>& result)
{
    vector<int> max_lis;
    vector<int> trace;
    trace.assign(array.size(), -1);
    
    max_lis.push_back(-1);
    
    for (int i=0; i<array.size(); i++) {
        for (int j=max_lis.size()-1; j>=0; j--)
        {
            if (max_lis[j] == -1 || array[i] > array[max_lis[j]])
            {
                if (j == max_lis.size() - 1)
                {
                    max_lis.push_back(i);
                }
                else
                {
                    max_lis[j+1] = i;
                }
                trace[i] = max_lis[j];
                break;
            }
        }
    }
    
    int first = max_lis.back();
    while (first != -1)
    {
        result.insert(result.begin(), array[first]);
        first = trace[first];
    }
}


void test_lis()
{
    vector<int> array, result, result_dp;
    
    for (int i=0; i<10; i++) {
        array.clear();
        result.clear();
        result_dp.clear();
        
        build_random_array(10, 10, array);
        print_array(array);
        
        lis_brute_force(array, result);
        lis_dp(array, result_dp);
        
        cout << "LIS brute force: ";
        print_array(result);
        cout << "LIS dp         : ";
        print_array(result_dp);
        
        cout << endl;
    }
}