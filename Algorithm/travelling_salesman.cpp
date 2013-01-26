//
//  travelling_salesman.cpp
//  Algorithm
//
//  Created by Shuai on 8/14/12.
//
//

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool compareX(const pair<int, int>& left, const pair<int, int>& right)
{
    return left.first < right.first;
}

double point_distance(vector<pair<int, int> > & points, int l, int r)
{
    if (l == 0 || r == 0)
        return 0;

    pair<int, int> left = points[l-1];
    pair<int, int> right = points[r-1];

    return sqrt((left.first - right.first)*(left.first - right.first) + (left.second - right.second)*(left.second - right.second));
}

double shortest_bitonic_path(vector<pair<int, int> > & points)
{
    sort(points.begin(), points.end(), compareX);
    
    double distance[points.size()+1][points.size()+1];
    for (size_t i=0; i<points.size()+1; i++)
    {
        distance [i][0] = distance[0][i] = 0;
    }
    
    
    for (size_t k=1; k<points.size()+1; k++)
    {    
        for (size_t i=k; i<points.size()+1; i++)
        {
            if (i == k)
            {
                double min_distance = distance[k][k-1] + point_distance(points, k-1, k);

                for (int j=1; j<k-1; j++)
                {
                    double d = distance[k-1][j] + point_distance(points, j, k) + point_distance(points, k-1, k);
                    if (d < min_distance)
                        min_distance = d;
                }
                distance[k][k] = min_distance;
            }
            else if (i == k+1)
            {
                double min_distance = distance[k][k] + point_distance(points, k, k+1);
                
                for (int j=1; j<k; j++) {
                    double d = distance[k][j] + point_distance(points, j, i);
                    if (d < min_distance)
                        min_distance = d;
                }
                distance[i][k] = distance[k][i] = min_distance;
            }
            else
            {
                distance[i][k] = distance[k][i] = distance[k][i-1] + point_distance(points, i, i-1);
            }
        }
    }
    
    return distance[points.size()][points.size()];
}

void test_travelling_salesman()
{
    vector<pair<int, int> >  pts;
    pts.push_back(make_pair(0, 0));
    pts.push_back(make_pair(2, 3));
    pts.push_back(make_pair(5, 2));
    pts.push_back(make_pair(7, 1));
    pts.push_back(make_pair(8, 4));
    pts.push_back(make_pair(6, 5));
    pts.push_back(make_pair(1, 6));
    
    cout << "Shortest distance: " << shortest_bitonic_path(pts) << endl;
}