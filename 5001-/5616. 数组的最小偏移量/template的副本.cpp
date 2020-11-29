//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/110359264
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minv = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(x % 2) x *= 2;
            pq.push(x);
            minv = min(minv, x);
        }
        int res = pq.top() - minv;
        while(pq.top() % 2 == 0) {
            int x = pq.top();
            pq.pop();
            x /= 2;
            minv = min(minv, x);
            pq.push(x);
            res = min(res, pq.top() - minv);
        }
        return res;
    }
};
