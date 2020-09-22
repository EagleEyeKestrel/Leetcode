//
//  main.cpp
//  送分题，而且不用排序
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size(), res = 0;
        if(!n) return 0;
        //sort(timeSeries.begin(), timeSeries.end());
        for(int i = 0; i < n - 1; i++) {
            res += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return res + duration;
    }
};
