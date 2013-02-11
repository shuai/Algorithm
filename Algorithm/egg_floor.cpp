//
//  egg_floor.cpp
//  Algorithm
//
//  Created by Shuai on 2/8/13.
//
//

//You are given two identical eggs and have access to a 100-story building.
//The eggs can be hard or fragile means an egg may break if dropped from the
//first floor or may not break if dropped from the 100th floor.
//
//How many drops are needed to identify the highest floor from which an egg
//can be dropped without breaking? (You may break both eggs in the process
//of solving the problem)
//

#include "include.h"

int solve(int floor) {
    int count = floor;
    for (int gap = 1; gap <= floor; gap++) {
        int c = floor/gap + gap - 1;
        count = std::min(count, c);
    }
    return count;
}

void test_egg() {
    for (int floor = 0; floor <= 200; floor++) {
        cout << "Times of drops for " << floor << " floors: " << solve(floor) << endl;
    }
}