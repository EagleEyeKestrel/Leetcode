//
//  main.cpp
//  比较简单，按结束时间排序
//  dp[i]表示0-i能获得的最大报酬，预处理pre[i] 表示结束时间在start[i]之前的索引
//  dp方程dp[i]=max(dp[i-1],profit[i]+dp[pre[i]])
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct job {
        int x, y, z;
        job() {
            x = 0, y = 0, z = 0;
        }
        job(int _x, int _y, int _z) {
            x = _x, y = _y, z = _z;
        }
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        job jobs[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = job(startTime[i], endTime[i], profit[i]);
        }
        sort(jobs, jobs + n, [](job &ja, job &jb) {
            if (ja.y == jb.y) return ja.x < jb.x;
            return ja.y < jb.y;
        });
        int dp[n], pre[n], end[n];
        for (int i = 0; i < n; i++) end[i] = jobs[i].y;
        pre[0] = -1;
        for (int i = 1; i < n; i++) {
            int id = upper_bound(end, end + n, jobs[i].x) - end;
            if (id == 0) pre[i] = -1;
            else pre[i] = id - 1;
        }
        dp[0] = jobs[0].z;
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], jobs[i].z + (pre[i] == -1 ? 0 : dp[pre[i]]));
        }
        return dp[n - 1];
    }
};
