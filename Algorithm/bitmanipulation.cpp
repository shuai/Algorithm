//
//  bitmanipulation.cpp
//  Algorithm
//
//  Created by Shuai on 9/10/12.
//
//

#include <vector>
#include <iostream>

using namespace std;

void print_binary(unsigned i)
{
    unsigned bits = sizeof(i)*8;
    bool print0 = false;
    while (bits--) {
        if (i & (1 << bits)) {
            print0 = true;
            cout << 1;
        }
        else if (print0)
            cout << 0;
    }
}

unsigned biggerNum(unsigned n)
{
    unsigned bits = sizeof(n)*8;
    unsigned numberof1 = 0;
    for (unsigned i=0; i<bits-1; i++) {
        if (n & (1u << i)) {
            if ((n & (1u << (i+1))))
            {
                numberof1 ++;
            }
            else
            {
                n &= ~0u << (i+1);
                n |= (1u << (i+1));
                if (numberof1)
                    n |= ~0u >> (bits - numberof1);
                return n;
            }
        }
    }
}

string add_binary(const string& value1, const string& value2)
{
    string carry;
    carry.resize(1+max(value1.size(), value2.size()), '0');

    string longger = value1.size() > value2.size() ? value1 : value2;
    string shorter = value1.size() > value2.size() ? value2 : value1;

    bool flag = true;
    while (flag) {
        flag = false;
        for (unsigned i=0; i<shorter.size(); i++) {
            char bit_l = longger[longger.size() - i - 1];
            char bit_s = shorter[shorter.size() - i - 1];
            if (bit_l == '1' && bit_s == '1') {
                flag = true;
                carry[carry.size()-i-2] = '1';
            }
            
            longger[longger.size() - i - 1] = bit_l == bit_s ? '0' : '1';
        }
        
        if (flag) {
            shorter = longger;
            longger = carry;
        }
    }
    
    return longger;
}

void test_add_binary()
{
    string str1 = "011";
    string str2 = "0011";
    
    cout << str1 << " + " << str2 << " = " << add_binary(str1, str2) << endl;
}

void test_binary()
{
    
    print_binary(1);
    cout << endl;
    print_binary(biggerNum(1));
    cout << endl;
    
    print_binary(3);
    cout << endl;
    print_binary(biggerNum(3));
    cout << endl;
    
    print_binary(10);
    cout << endl;
    print_binary(biggerNum(10));
    cout << endl;
    
    print_binary(11);
    cout << endl;
    print_binary(biggerNum(11));
    cout << endl;
    
    print_binary(16);
    cout << endl;
    print_binary(biggerNum(16));
    cout << endl;
    
    print_binary(22);
    cout << endl;
    print_binary(biggerNum(22));
    cout << endl;
    
    print_binary(56);
    cout << endl;
    print_binary(biggerNum(56));
    cout << endl;
}