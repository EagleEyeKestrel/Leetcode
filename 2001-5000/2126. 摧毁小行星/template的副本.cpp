//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        //.... x y ...
        //mass+s[i-1] >= x  mass+s[i-1]+x >= y
        //mass+s[i-1] >= y  mass+s[i-1]+y >= x
        //x > y
        sort(asteroids.begin(), asteroids.end());
        long long now = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (now >= asteroids[i]) {
                now += asteroids[i];
            } else {
                return false;
            }
        }
        return true;
    }
};