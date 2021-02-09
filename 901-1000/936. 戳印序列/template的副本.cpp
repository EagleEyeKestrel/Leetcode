//
//  main.cpp
//  大致思路是，逆向贪心，找到可以修改的位置，然后做更改
//  比如abca和aabcaca，首先肯定考虑中间的abca，变成a????ca，然后发现第一个也可以改，然后是0，然后是3
//  但是实现方式有很多，这里是一种偏暴力的实现方法。开始记录所有可以修改的索引集合s
//  因为每个索引左端点肯定最多印一次。然后就暴力匹配，找到可以更改的索引
//  这种算法感觉最坏情况下复杂度会达到n3，但是也很快过了，说明这题只在乎实现，不太在意效率
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int match(string& target, string& stamp, int base) {
        for (int i = 0; i < stamp.size(); i++) {
            if (target[i + base] != '?' && target[i + base] != stamp[i]) {
                return 0;
            }
        }
        int res = 0;
        for (int i = 0; i < stamp.size(); i++) {
            if (target[i + base] != '?') {
                target[i + base] = '?';
                res++;
            }
        }
        return res;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> res;
        set<int> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) s.insert(i);
        while (cnt < n) {
            int flag = 0;
            for (auto it = s.begin(); it != s.end(); ) {
                int tmp = match(target, stamp, *it);
                if (tmp > 0) {
                    flag = 1;
                    cnt += tmp;
                    res.push_back(*it);
                    s.erase(it);
                }
                it++;
            }
            if (!flag) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
