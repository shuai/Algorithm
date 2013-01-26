//
//  LCS.cpp
//  Algorithm
//
//  Created by  on 7/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

int LCS(int* const array1, unsigned size1, int* const array2, unsigned size2);

void testLCS()
{
    int array1[] = {2,3,4,5,6,7,8,10,12};
    int array2[] = {2,3,4,5,6,7,8,10,12};
    
    std::cout << "test LCS: " << LCS(array1, sizeof(array1)/sizeof(array1[0]), array2, sizeof(array2)/sizeof(array2[0])) << std::endl;
    
}

int LCS(int* const array1, unsigned size1, int* const array2, unsigned size2)
{
    if (!array1 || !array2 || !size1 || !size2)
        return 0;
    
    int result[size1+1][2];
    memset(result, 0, sizeof(result));
    bool current = true;
    
    for (int i=0; i < size2; i++) {
        for (int j=0; j < size1; j++) {
            //cout << "step " << i << " " << j << " ";
            if (array1[j] == array2[i]) {
                result[j+1][current] = result[j][!current] + 1;
                //cout << " equal " << result[j+1][current] << endl;
            }
            else {
                result[j+1][current] = std::max(result[j][current], result[j+1][!current]);
                //cout << " unequal " << result[j+1][current] << endl;
            }
        }
        current = !current;
    }
    
    return result[size1][!current];
}