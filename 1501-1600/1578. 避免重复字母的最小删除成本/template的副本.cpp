//
//  main.cpp
//  对于所有连续序列，保留删除成本最大的那个
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        vector<int> v, num;
        int i = 0, n = s.size(), res = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[i]) j++;
            v.push_back(i);
            num.push_back(j - i + 1);
            i = j + 1;
        }
        for (int k = 0; k < v.size(); k++) {
            int s = 0, maxv = -1;
            for (int t = v[k]; t < v[k] + num[k]; t++) {
                s += cost[t];
                maxv = max(maxv, cost[t]);
            }
            res += s - maxv;
        }
        return res;
    }
};
