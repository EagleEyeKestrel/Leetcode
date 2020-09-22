//
//  main.cpp
//  签到题
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h = heights;
        sort(h.begin(), h.end());
        int res = 0;
        for(int i = 0; i < h.size(); i++) {
            if(h[i] != heights[i]) res++;
        }
        return res;
    }
};
