//
//  arbitrage.cpp
//  Algorithm
//
//  Created by Shuai on 9/17/12.
//
//

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;


void find_arbitrage(vector<vector<float> >& exchange, unsigned side)
{
    float currency[side];
    unsigned parent[side];
    
    for (int i=0; i<side; i++) {
        currency[side] = 0;
    }
    
    parent[0] = ~0u;
    
    currency[0] = 1;
    for (int i=0; i<side; i++) {
        for (int curr=0; curr<side; curr++) {
            for (int curr2=0; curr2<side; curr2++) {
                if (curr != curr2 && currency[curr]*exchange[curr][curr2] > currency[curr2]) {
                    currency[curr2] = currency[curr]*exchange[curr][curr2];
                    parent[curr2] = curr;
                }
            }
        }
    }
    
    // locate a vertex which trace back to a cycle in predecessor tree
    for (int u=0; u<side; u++) {
        for (int v=0; v<side; v++) {
            if (u != v && currency[u]*exchange[u][v] > currency[v]) {                
                for (unsigned i=0; i<side; i++) {
                    u = parent[u];
                }
                
                vector<unsigned> cycle;
                unsigned start = u;
                while (true) {
                    cycle.push_back(u);
                    u = parent[u];
                    if (u == start) {
                        break;
                    }
                }
                reverse(cycle.begin(), cycle.end());
                
                assert(cycle.size() > 1);
                cout << cycle[0] << "(1)-->";
                float money = 1;
                for (unsigned i=1; i<cycle.size(); i++) {
                    money *= exchange[cycle[i-1]][cycle[i]];
                    cout << cycle[i] << "(*" << exchange[cycle[i-1]][cycle[i]] << '=' << money << ')' << "-->";
                }
                
                money *= exchange[cycle.back()][cycle[0]];
                cout << cycle.front() << "(*" << exchange[cycle.back()][cycle[0]] << '=' << money << ')';
                
                return;
            }
        }
    }

    
    cout << "no arbitrage" << endl;
    
//    enum State
//    {
//        Visited,
//        Visiting,
//        New
//    } states[side];
//    
//    for (int i=0; i<side; i++) {
//        states[i] = New;
//    }    
//    unsigned index = 0;
//    while (true) {
//        while (index < side && states[index] == Visited) {
//            index ++;
//        }
//        
//        if (index == side) {
//            break;
//        }
//        
//        vector<unsigned> stack;
//        unsigned current = index;
//        while (true) {
//            if (states[current] == Visited) {
//                break;
//            }
//            else if (states[current] == Visiting)
//            {
//                assert(!stack.empty());
//                // found loop
//                int stack_i = stack.size() - 1;
//                cout << stack[stack_i--] << "(1)-->";
//
//                float start = 1;
//                while (stack_i >= 0) {
//                    start *= exchange[stack[stack_i+1]][stack[stack_i]];
//                    cout << stack[stack_i] << "(*" << exchange[stack[stack_i+1]][stack[stack_i]] << '=' << start << ')' << "-->";
//                    
//                    if (stack[stack_i] == current)
//                        break;
//                    
//                    stack_i --;
//                }
//                
//                assert(stack[stack_i] == current);
//                start*= exchange[current][stack[stack.size()-1]];
//                
//                cout << stack[stack.size()-1] << "(*" << exchange[current][stack[stack.size()-1]] << '=' << start << ')' << endl;
//                break;
//            }
//            else
//            {
//                stack.push_back(current);
//                states[current] = Visiting;
//                if (parent[current] != ~0u) {
//                    current = parent[current];
//                }
//                else
//                    break;
//            }
//        }
//        
//        // mark all as visited
//        for (int i=0; i<stack.size(); i++) {
//            states[stack[i]] = Visited;
//        }
//    }
}


void test_arbitrage()
{
    vector<vector<float> > exchange;
    exchange.resize(4);
    
    exchange[0].push_back(1.f);
    exchange[0].push_back(2.f);
    exchange[0].push_back(4.f);
    exchange[0].push_back(8.f);
    
    exchange[1].push_back(0.50f);
    exchange[1].push_back(1.f);
    exchange[1].push_back(2.0f);
    exchange[1].push_back(3.9f);
    
    exchange[2].push_back(0.2f);
    exchange[2].push_back(0.51f);
    exchange[2].push_back(1.f);
    exchange[2].push_back(1.91f);
    
    exchange[3].push_back(.12f);
    exchange[3].push_back(.2f);
    exchange[3].push_back(.50f);
    exchange[3].push_back(1.f);
    
    find_arbitrage(exchange, 4);
}