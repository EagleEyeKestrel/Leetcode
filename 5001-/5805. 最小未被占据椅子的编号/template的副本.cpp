//
//  main.cpp
//  主要是时间的范围不会超过1e5，那就比较好办了
//  用一个优先队列存储最小的椅子。记录每个时间点到达/离开的人
//  chair存一下每个人占了哪个椅子
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= 1e5; i++) pq.push(i);
        int arr[100010], chair[n];
        vector<int> leave[100010];
        for (int t = 1; t <= 1e5; t++) arr[t] = -1;
        for (int i = 0; i < n; i++) {
            auto v = times[i];
            arr[v[0]] = i;
            leave[v[1]].push_back(i);
        }
        for (int t = 1; t <= 1e5; t++) {
            for (int p: leave[t]) {
                int pChair = chair[p];
                pq.push(pChair);
            }
            if (arr[t] != -1) {
                int p = arr[t];
                chair[p] = pq.top();
                if (p == targetFriend) return chair[p];
                pq.pop();
            }
        }
        return 0;
    }
};
