//
//  main.cpp
//  用l[i]表示i以左最多的连续递减个数，r[i]表示i往右最多的连续递增个数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n = s.size();
        int l[n], r[n];
        l[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] >= s[i]) {
                l[i] = l[i - 1] + 1;
            } else {
                l[i] = 1;
            }
        }
        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] <= s[i + 1]) {
                r[i] = r[i + 1] + 1;
            } else {
                r[i] = 1;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (l[i] >= time + 1 && r[i] >= time + 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};
