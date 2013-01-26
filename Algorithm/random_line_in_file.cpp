//
//  random_line_in_file.cpp
//  Algorithm
//
//  Created by  on 7/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string random_line(const char* filename)
{
    ifstream stream;
    stream.open(filename);
    string line, current;
    
    int i=0;

    while (getline(stream, current))
    {
        //cout << "reading line " << current << endl;
        i++;
        if (rand()%i == 0)
            line.swap(current);
    }
    return line;
}

void test_random_line()
{
    srand(time(NULL));

    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
    cout << random_line("/Users/shuais/Desktop/Algorithm/Algorithm/test_file.txt") << endl;
 
}