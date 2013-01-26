//
//  nearest_point.cpp
//  Algorithm
//
//  Created by  on 7/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include "cstdlib"
#include "cmath"
#include "cfloat"

using namespace std;

struct Point
{
    int x;
    int y;
};

int compareX(const void * left, const void *right)
{
    Point* l = (Point*)left;
    Point* r = (Point*)right;
    
    if (l->x < r->x)
        return -1;
    else if (l->x == r->x)
        return 0;
    else {
        return 1;
    }
}

int compareY(const void * left, const void *right)
{
    Point* l = (Point*)left;
    Point* r = (Point*)right;
    
    if (l->y < r->y)
        return -1;
    else if (l->y == r->y)
        return 0;
    else {
        return 1;
    }
}

double find_nearest_point(Point* points, unsigned size)
{
    if (size < 2)
        return DBL_MAX;
    else if (size == 2)
        return sqrt(pow((double)points[0].x - points[1].x, 2) + pow((double)points[0].y - points[1].y, 2));
    
    qsort(points, size, sizeof(Point), compareX);
    
    double midpoint = points[size/2].x;
    
    double left = find_nearest_point(points, size/2);
    double right = find_nearest_point(points + size/2, size - size/2);
    double min_distance = min(left, right);
    
    int first = -1, last = -1;
    
    for (int i=0; i<size; i++) {
        if (points[i].x >= midpoint - min_distance &&  points[i].x <= midpoint + min_distance)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    
    if (first == -1 && last == -1)
        return min_distance;
    
    qsort(points+first, last-first+1, sizeof(Point), compareY);
    
    for (int i=first; i<last; i++)
    {
        for (int j=i+1; j<i+8 && j<=last; j++)
        {
            double distance = sqrt(pow((double)points[i].x - points[j].x, 2) + pow((double)points[i].y - points[j].y, 2));
            if (distance < min_distance)
                min_distance = distance;
        }
    }
    
    return min_distance;
}

void test_nearest_point()
{
    Point array1[1];
    array1->x = 1;
    array1->y = 1;
    
    cout << "Nearest points, 1 point: " << find_nearest_point(array1, 1) << endl;
    
    Point array2[2];
    array2->x = 1;
    array2->y = 1;
    array2[1].x = 4;
    array2[1].y = 5;
    
    cout << "Nearest points, 2 point: " << find_nearest_point(array2, 2) << endl;
    
    srand(time(NULL));
    
    for (int i=0; i<100; i++) {
        unsigned count = rand()%10000 + 1;
        Point* array = new Point[count];
        
        for (int j=0; j<count; j++) {
            array[j].x = rand()%10000;
            array[j].y = rand()%10000;
        }
        
        double min_distance = DBL_MAX;
        for (int j=0; j<count-1; j++) {
            for (int k=j+1; k<count; k++) {
                double distance = sqrt(pow((double)array[j].x - array[k].x, 2) 
                                       + pow((double)array[j].y - array[k].y, 2));
                if (distance < min_distance)
                    min_distance = distance;
            }
        }
        
        cout << "Randomly generated array, count: " << count << " nearest distance: " << min_distance << " result: " << find_nearest_point(array, count) << endl;
    }
}


//void find_collear(vector<pair<int, int> >& points)
//{
//vector<pair<int, int> >& endPoints;
//
//for (size_t i=0; i<points.size(); i++) {
//    endPoints
//}
//}

