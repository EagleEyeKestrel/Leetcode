//
//  main.cpp
//  这题对时间还是有要求的，比赛的时候t了一次
//  一个，开始用map，现在用数组，因为不用存储>1000的数字，判断一下是否是goal即可
//  我尝试用一个vector存储循环里的三个数，直接变成1000+ms。。。这种朴素写法只要20ms
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int mp[1010];
        memset(mp, 0, sizeof(mp));
        mp[start] = 1;
        if (start == goal) return 0;
        int n = nums.size();
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            if (tmp > 1000 || tmp < 0) continue;
            int step = mp[tmp];
            for (int i = 0; i < n; i++) {
                int x = nums[i];
                if (x + tmp == goal || tmp - x == goal || (tmp ^ x) == goal) return step;
                if (x + tmp >= 0 && x + tmp <= 1000 && !mp[x + tmp]) {
                    mp[x + tmp] = step + 1;
                    q.push(x + tmp);
                }
                if (tmp - x >= 0 && tmp - x <= 1000 && !mp[tmp - x]) {
                    mp[tmp - x] = step + 1;
                    q.push(tmp - x);
                }
                if ((tmp ^ x) >= 0 && (tmp ^ x) <= 1000 && !mp[tmp ^ x]) {
                    mp[tmp ^ x] = step + 1;
                    q.push(tmp ^ x);
                }
            }
        }
        return -1;
    }
};
