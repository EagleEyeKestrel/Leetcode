//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int now = 0;
        for(int x: A) {
            now = ((now << 1) + x) % 5;
            res.push_back(!now);
        }
        return res;
    }
};
