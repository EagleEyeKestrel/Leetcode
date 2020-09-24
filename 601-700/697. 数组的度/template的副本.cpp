//
//  main.cpp
//  简单题，实现的也比较朴素， 把出现最多的元素的始末位置找出来，算最小值
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int cnt[50000], start[50000], end[50000];
        memset(cnt, 0, sizeof(cnt));
        memset(start, 0, sizeof(start));
        memset(end, 0, sizeof(end));
        int maxd = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            maxd = max(maxd, cnt[nums[i]]);
            if(!start[nums[i]]) start[nums[i]] = i + 1;
            end[nums[i]] = i + 1;
        }
        int res = INT_MAX;
        for(int i = 0; i < 50000; i++) {
            if(cnt[i] == maxd) {
                res = min(res, end[i] - start[i] + 1);
            }
        }
        return res;
    }
};
