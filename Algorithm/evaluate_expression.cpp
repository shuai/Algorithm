//
//  expression.cpp
//  Algorithm
//
//  Created by Shuai on 2/8/13.
//
//


//给一个表达式，计算返回值，不带括号
//
//例子
//"7-12/6"
//"1000-5*6/3*2+1"

#include "include.h"

double calculate(const char* str) {
    vector<double> operands;
    vector<char> operators;
    
    double num = 0;
    do {
        bool clear = false;
        
        switch (*str) {
            case '+':
            case '-':
            case 0:
                clear = true;
            case '*':
            case '/':
                operands.push_back(num);
                while (operands.size() >= 2 && (clear || operators.back() == '*' || operators.back() == '/')) {
                    double operand = operands.back();
                    operands.pop_back();
                    switch (operators.back()) {
                        case '*':
                            operands.back() *= operand;
                            break;
                        case '/':
                            operands.back() /= operand;
                            break;
                        case '+':
                            operands.back() += operand;
                            break;
                        case '-':
                            operands.back() -= operand;
                            break;
                        default:
                            break;
                    }
                    operators.pop_back();
                }
                
                operators.push_back(*str);
                num = 0;
                break;
            default:
                assert(*str >= '0' && *str <= '9');
                num = num*10 + *str - '0';
                break;
        } 
    } while (*str++);
    
    assert(operands.empty() || operands.size() == 1);
    
    return operands.size() ? operands.front() : 0;
}

void test_expression() {
    double value = calculate("1000-5*6/3*2+1");
    cout << "Evaluating expression: " << value << endl;
}