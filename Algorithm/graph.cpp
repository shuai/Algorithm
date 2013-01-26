//
//  graph.cpp
//  Algorithm
//
//  Created by Shuai on 8/25/12.
//
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <cassert>

using namespace std;

#include "test.h"

void bfs(unsigned v, vector<bool>& graph)
{
    list<unsigned> q;
    vector<unsigned> distance;
    distance.resize(v);
    distance.assign(v, ~0);
    
    q.push_back(0);
    distance[0] = 0;
    
    while (!q.empty()) {
        unsigned current = q.back();
        q.pop_back();
        cout << current << "(" << distance[current] << ") ";
        
        for (unsigned i=0; i<v; i++)
        {
            if (i != current && graph[current*v + i] && distance[i] == ~0)
            {
                q.push_front(i);
                distance[i] = distance[current]+1;
            }
        }
    }
}

void topological_sort(unsigned v, vector<bool>& graph)
{
    vector<unsigned> stack;
    vector<unsigned> tree;

    vector<bool> visited;
    list<unsigned> sorted;
    
    visited.resize(v);
    tree.resize(v);

    
    while (true) {
        unsigned start = ~0;
        for (unsigned i=0; i<visited.size(); i++) {
            if (!visited[i])
            {
                start =  i;
                break;
            }
        }
        
        if (start == ~0)
            break;
        
        stack.push_back(start);
        
        while (!stack.empty()) {
            unsigned vertex = stack.back();
            visited[vertex] = true;
  
            for (unsigned i=0; i<v; i++) {
                if (graph[vertex*v + i] && i != vertex && !visited[i])
                {
                    stack.push_back(i);
                    tree[i] = vertex;
                }
            }
            
            while (!stack.empty() && stack.back() == vertex)
            {
                sorted.push_front(vertex);
                stack.pop_back();
                vertex = tree[vertex];
            }
        }
    }

    for (list<unsigned>::iterator start = sorted.begin(); start != sorted.end(); start++) {
        cout << *start << " ";
    }
}

//Exercises 22.4-2
//
//Give a linear-time algorithm that takes as input a directed acyclic graph G = (V, E) and two vertices s and t, and returns the number of paths from s to t in G. For example, in the directed acyclic graph of Figure 22.8, there are exactly four paths from vertex p to vertex v: pov, por yv, posr yv, and psr yv. (Your algorithm only needs to count the paths, not list them.)

unsigned count_path_bfs(unsigned v, unsigned start, unsigned dest, vector<bool>& graph)
{
    vector<unsigned> stack;
    vector<unsigned> child;
    child.resize(v);
    child.assign(v, ~0);
    
    stack.push_back(start);
    
    unsigned count = 0;
    
    while (!stack.empty()) {
        unsigned vertex = stack.back();
        
        if (vertex == dest)
            count ++;
        else
        {
            for (unsigned i=0; i<v; i++) {
                if (graph[vertex*v + i] && i != vertex)
                {
                    stack.push_back(i);
                    if (child[vertex] == ~0)
                        child[vertex] = i;
                }
            }
        }
        
        if (child[vertex] == ~0)
            child[vertex] = vertex;
        
        while (!stack.empty() && child[stack.back()] == vertex)
        {
            vertex = stack.back();
            stack.pop_back();
            child[vertex] = ~0;
        }
    }
    return count;
}

unsigned count_path_dfs(unsigned v, unsigned start, unsigned dest, vector<bool>& graph)
{
    return 0;
}

// floyd

bool floyd(vector<vector<int> >& array)
{
    unsigned v=array.size();
    for (unsigned c=0; c<v; c++) {
        for (unsigned i=0; i<v; i++) {
            for (unsigned j=0; j<v; j++) {
                if (array[i][c] != INT_MAX && array[c][j] != INT_MAX && array[i][c] + array[c][j] < array[i][j]) {
                    array[i][j] = array[i][c] + array[c][j];
                }
            }
        }
    }
    
    for (unsigned i=0; i<v; i++) {
        if (array[i][i] < 0) {
            return false;
        }
    }
    
    return true;
}

//Exercises 22.3-12: ⋆
//
//A directed graph G = (V, E) is singly connected if  implies that there is at most one simple path from u to v for all vertices u, v ∈ V. Give an efficient algorithm to determine whether or not a directed graph is singly connected.
//


bool bellmanford(vector<vector<int> >& graph, vector<vector<int> >& distance)
{
    for (unsigned s=0; s<graph.size(); s++) {
        
        for (int i=0; i<graph.size(); i++) {
            distance[s][i] = INT_MAX;
        }
        distance[s][s] = 0;
        
        bool changed = false;
        for (int i=0; i<graph.size(); i++) {
            for (int j=0; j<graph.size(); j++) {
                for (int k=0; k<graph[j].size(); k++) {
                    if (distance[s][j] != INT_MAX && graph[j][k] != INT_MAX)
                    {
                        int d = graph[j][k] + distance[s][j];
                        if (d < distance[s][k])
                        {
                            distance[s][k] = d;
                            changed = true;
                        }
                    }
                }
            }
            
            if (!changed) {
                break;
            }
        }
        
        for (int j=0; j<graph.size(); j++) {
            for (int k=0; k<graph[j].size(); k++) {
                if (distance[s][j] != INT_MAX && graph[j][k] != INT_MAX && distance[s][j] + graph[j][k] < distance[s][k]) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

// determine if a graph is semiconnected
// component graph -> topological sort -> check each adjacent pair of verteies
void component_graph(unsigned v, vector<bool>& graph)
{
    vector<unsigned> f;
    f.reserve(v);
    
    vector<bool> visited;
    visited.resize(v);
    
    // run a dfs on the graph and compute finish time of each vertex
    unsigned current_v = 0, timestamp = 0;
    vector<unsigned> stack;
    while (!visited[current_v]) {
        
        visited[current_v] = true;
        while (current_v) {
            
            for (unsigned i=0; i<v; i++) {
                if (graph[current_v*v+i] && !visited[i]) {
                    stack.push_back(current_v);
                    current_v = i;
                    
                    break;
                }
            }
            
            // found new node to explore
            if (visited[current_v]) {
                assert(timestamp < v);
                f[timestamp++] = current_v;
                if (stack.empty()) {
                    current_v = 0;
                }
                else {
                    current_v = stack.back();
                    stack.pop_back();
                }
            }
            else {
                visited[current_v] = true;
            }
        }

        for (unsigned i=0; i<v; i++) {
            if (!visited[i]) {
                current_v = i;
                break;
            }
        }
    }
    
    // 
}


void is_semiconnected()
{
    
}


void test_shortest_path()
{
    vector<vector<int> > array, output;
    build_weighted_dag(array);
    output.resize(array.size());
    for (unsigned i=0; i<output.size(); i++) {
        output[i].resize(output.size());
    }
    
    print_matrix(array);
    
    if (bellmanford(array, output))
        print_matrix(output);
    else
        cout << "Negative weight loop detected" << endl;

    if (floyd(array))
        print_matrix(array);
    else
        cout << "Negative weight loop detected" << endl;
}

void test_undirected_bfs()
{
    vector<bool> dag;
    unsigned size = 14;
    
    build_dag(dag);
    topological_sort(size, dag);
    
    //cout << "Counting paths from 3 - 9 : " << count_path(size, 3, 9, dag) << endl;
    
}
