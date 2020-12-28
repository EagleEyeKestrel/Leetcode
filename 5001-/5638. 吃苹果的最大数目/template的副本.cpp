//
//  main.cpp
//  优先吃最快要过期的苹果，用个堆存一下
//  循环内的步骤：把今天长出来的苹果放进堆；过期的苹果淘汰；吃苹果
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < 40000; i++) {
            if (i < n && apples[i]) {
                q.push({i + days[i], apples[i]});
            }
            while (!q.empty() && q.top().first <= i) {
                q.pop();
            }
            if (q.empty()) {
                if (i < n) continue;
                else break;
            }
            pair<int, int> tmp = q.top();
            q.pop();
            tmp.second--;
            if (tmp.second) q.push(tmp);
            res++;
        }
        return res;
    }
};
