//
//  main.cpp
//  最基础的离线查询
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto &v1, auto &v2) {
            return v1[0] < v2[0];
        });
        int Q = queries.size();
        vector<int> res(Q), id(Q);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) {
            return queries[x] < queries[y];
        });
        priority_queue<int> q;
        int now = 0;
        for (int i = 0; i < Q; i++) {
            int qid = id[i];
            int bound = queries[qid];
            while (now < items.size() && items[now][0] <= bound) {
                q.push(items[now][1]);
                now++;
            }
            res[qid] = q.empty() ? 0 : q.top();
        }
        return res;
    }
};
