//
//  reverse_sentence.cpp
//  Algorithm
//
//  Created by  on 7/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>


void reverse_string(char* str, unsigned size)
{
    if (!str || size < 2)
        return;
    
    for (unsigned i=0; i<size/2; i++)
    {
        str[i] ^= str[size-i-1];
        str[size-i-1] ^= str[i];
        str[i] ^= str[size-i-1];
    }
}

void reverse_sentence(char* str)
{
    if (!str)
        return;
    
    unsigned size = strlen(str);
    reverse_string(str, size);
    
    unsigned word_start = 0;
    for (unsigned i=0; i<size; i++)
    {
        if (str[i] == ' ')
        {
            reverse_string(str + word_start, i - word_start);
            word_start = i+1;
        }
    }
}
