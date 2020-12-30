//
//  main.cpp
//  注意这道题不是要求最少能留下多少，而是固定了每次取最大的两个
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (auto stone: stones) q.push(stone);
        while (q.size() >= 2) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (y > x) q.push(y - x);
        }
        if (q.size()) return q.top();
        return 0;
    }
};
