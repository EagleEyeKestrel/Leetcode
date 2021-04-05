//
//  main.cpp
//  只需要看同一种颜色的有多少个，num+1个兔子可以有相同的颜色
//  看能否整除，讨论
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (int x: answers) mp[x]++;
        int res = 0;
        for (auto it: mp) {
            int num = it.first, cnt = it.second;
            if (cnt % (num + 1) == 0) res += cnt;
            else {
                int kinds = cnt / (num + 1) + 1;
                res += kinds * (num + 1);
            }
        }
        return res;
    }
};
