//
//  main.cpp
//  弄个堆就好了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int res = 0;
        priority_queue<int> q;
        for (int x: piles) res += x, q.push(x);
        while (k--) {
            int x = q.top();
            q.pop();
            res -= x / 2;
            q.push(x - x / 2);
        }
        return res;
    }
};
