//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        for(int i = 0; i < startTime.size(); i++) {
            if(startTime[i] <= queryTime && endTime[i] >= queryTime) res++;
        }
        return res;
    }
};
