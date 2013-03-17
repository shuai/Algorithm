//
//  number.cpp
//  Algorithm
//
//  Created by  on 7/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

//Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.
void generate_nums(vector<unsigned>& factors, unsigned num)
{
    vector<int> numbers;
    unsigned last[factors.size()];
    memset(last, 0, sizeof(last));
    
    numbers.push_back(1);
    while (numbers.size() < num + 1) {
        unsigned number = ~0u;
        unsigned max = numbers[numbers.size()-1];
        for (int i=0; i<factors.size(); i++) {
            while (numbers[last[i]]*factors[i] <= max) {
                last[i]++;
            }
            
            unsigned newnum = numbers[last[i]]*factors[i];
            if (newnum < number) {
                number = newnum;
            }
        }
        numbers.push_back(number);
        cout << number << " ";
    }
}

void test_generate_nums()
{
    vector<unsigned> factors;
    factors.push_back(3);
    factors.push_back(5);
    factors.push_back(7);

    
    generate_nums(factors, 10);
}


// number to literate string
string number_to_string(unsigned num)
{
    static const char* below20[] = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
    };
    
    static const char* str10s[] = {
        "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };
    
    static const char* str100[] = {
        "hundred", "thousand", "million", "billion"
    };
    
    string str;
    if (num <= 999) {
        if (num >= 200)
        {
            str += below20[(num/100)];
            str.append(" ");
            str.append(str100[0]);
            str.append("s");
        }
        else if (num >= 100)
        {
            str.append("one hundred");
        }
        
        if (num >= 100)
        {
            num %= 100;
            if (num)
                str.append(" and ");
        }
        
        if (num < 20) {
            str.append(below20[num]);
        }
        else
        {
            str.append(str10s[num/10-2]);
            str.push_back(' ');
            str.append(below20[num%10]);
        }
        return str;
    }
    
    unsigned index = 0;
    while (num) {
        unsigned current = num % 1000;
        num /= 1000;
        
        string current_str = number_to_string(current);
        if (!str.empty()) {
            current_str += ' ';
            current_str += str100[index];
            if (current > 1) {
                current_str += 's';
            }
            current_str += ", " + str;
        }
        str = current_str;

        index ++;
    }
    return str;
}

void test_num_to_str()
{
    string str = number_to_string(2231122987);
    cout << str << endl;
    
    str = number_to_string(11);
    cout << str << endl;
    
    str = number_to_string(21);
    cout << str << endl;
    
    str = number_to_string(121);
    cout << str << endl;
    
    str = number_to_string(223);
    cout << str << endl;
}

int str2int(const string& str)
{
    if (str.empty()) {
        return 0;
    }
    
    bool minus = false;
    int index = 0;
    if (!isdigit(str[0])) {
        assert(str[0] == '-');
        minus = true;
        index = 1;
    }
    
    int ret = 0;
    while (index < str.size()) {
        ret = ret*10 + str[index] - '0';
        index ++;
    }
    
    return minus ? -ret : ret;
}

void test_str2int()
{
    const char* number = "-1234";
    
    cout << "converting " << number << " : " << str2int(number) << endl;
}

#define LOGERROR 0.00000001

double mylog2(double x)
{
    assert(x > 0);
    
    bool minus = false;
    bool oneover = false;
    
    double a = 2,b = x;
    if (b <= 1) {
        b = 1/b;
        minus = true;
    }
    
    if (b > 2){
        swap(a, b);
        oneover = true;
    }
    
    double min = 0, max = 1, minvalue = 1, maxvalue = a, delta = sqrt(a);
    double current;
    while (true) {
        current = (min+max)/2;
        double middle = minvalue*delta;
        if (middle < b - LOGERROR) {
            minvalue = middle;
            min = current;
        }
        else if (middle > b + LOGERROR){
            maxvalue = middle;
            max = current;
        }
        else
            break;
        
        delta = sqrt(delta);
    }
    
    if (oneover) {
        current = 1/current;
    }
    
    return minus ? -current : current;
}

void test_log2()
{
    cout << "log2(" << 1 << ") = " << log2(1) << " | " << mylog2(1) << endl;

    for (int i=0; i<10; i++) {
        double input = (rand()%10000 + 1)/100;
        cout << "log2(" << input << ") = " << log2(input) << " | " << mylog2(input) << endl;
    }
}

unsigned modular_exponentiation(unsigned base, unsigned exponent, unsigned modulus)
{
    unsigned e = 0;
    unsigned c = 1;
    while (e++ < exponent) {
        c = c*base%modulus;
    }
    return c;
}

unsigned modular_exponentiation2(unsigned base, unsigned exponent, unsigned modulus)
{
    unsigned c = 1;
    while (exponent) {
        if (exponent & 1) {
            c = c*base%modulus;
        }
        base = base*base%modulus;
        exponent >>= 1;
    }
    return c;
}

void test_modular_exponentiation()
{
    for (size_t i=0; i<10; i++) {
        unsigned base = rand()%5;
        unsigned exponent = rand()%8;
        unsigned modulus = rand()%10 + 2;
        cout << base << "^" << exponent << "%" << modulus << "=" << modular_exponentiation(base, exponent, modulus) << " | "
        << modular_exponentiation2(base, exponent, modulus) << endl;
    }
}

bool test_primality(unsigned number)
{
    if (modular_exponentiation2(2, number-1, number) != 1) {
        return false;
    }
    
    return true;
}

void test_test_primality()
{
    for (unsigned i=2; i<200; i++) {
        cout << i << ":" << test_primality(i) << endl;
    }
}

