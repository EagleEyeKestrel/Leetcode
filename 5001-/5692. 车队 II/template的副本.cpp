//
//  main.cpp
//  看到“消失”的汽车，要能想到单调栈。比赛的时候毫无思路，放弃了
//  题解完全参见
//  https://leetcode-cn.com/problems/car-fleet-ii/solution/cdan-diao-zhan-by-oldyan-ij4k/
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                res[i] = -1;
                st.push(i);
                continue;
            }
            while (!st.empty()) {
                if (cars[i][1] <= cars[st.top()][1]) {
                    st.pop();
                    continue;
                }
                if (res[st.top()] == -1) break;
                double dist = res[st.top()] * (cars[i][1] - cars[st.top()][1]);
                if (dist >= cars[st.top()][0] - cars[i][0]) break;
                else st.pop();
            }
            if (st.empty()) res[i] = -1;
            else {
                double t = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                res[i] = t;
            }
            st.push(i);
        }
        return res;
    }
};
