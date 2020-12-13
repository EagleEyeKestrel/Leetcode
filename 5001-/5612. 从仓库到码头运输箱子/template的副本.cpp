//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/111139874
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        long sPort[n + 1], pre[n + 1];
        sPort[1] = 0;
        for(int i = 2; i <= n; i++) {
            sPort[i] = sPort[i - 1];
            if (boxes[i - 1][0] != boxes[i - 2][0]) sPort[i]++;
        }

        pre[1] = 1;
        long l = 1, nowBoxes = 1, nowW = boxes[0][1];
        for(int i = 2; i <= n; i++) {
            nowBoxes++;
            nowW += boxes[i - 1][1];
            while(nowBoxes > maxBoxes || nowW > maxWeight) {
                nowBoxes--;
                nowW -= boxes[l - 1][1];
                l++;
            }
            pre[i] = l;
        }
        
        deque<pair<long, long>> q;
        int res = INT_MAX;
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            while (!q.empty() && q.front().first < pre[i]) q.pop_front();
            while (!q.empty() && q.back().second >= dp[i - 1] - sPort[i]) q.pop_back();
            q.push_back({i, dp[i - 1] - sPort[i]});
            dp[i] = q.front().second + sPort[i] + 2;
        }
        return dp[n];
    }
};
