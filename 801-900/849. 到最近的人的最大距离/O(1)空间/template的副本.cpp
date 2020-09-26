//
//  main.cpp
//  记录开头，中间和最后连续最多的1 的个数
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int firstOne, lastOne, now = 0;
        for(int i = 0; i < n; i++) {
            if(seats[i]) {
                firstOne = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(seats[i]) {
                lastOne = i;
                break;
            }
        }
        int res = max(firstOne, n - 1 - lastOne);
        for(int i = firstOne; i <= lastOne; i++) {
            if(seats[i]) {
                now = 0;
            } else {
                now++;
                res = max(res, (now + 1) / 2);
            }
        }
        return res;
    }
};
