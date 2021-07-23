//
//  main.cpp
//  既然不算重复的，那么自然想到计数。
//  可以穷举长度为3的所有序列，复杂度是O(26*26)
//  对于每个序列，我们只需判断这个子序列是否存在。对于iji这样的子序列
//  我们只需查看第一个i和最后一个i的索引
//  然后看是否存在介于中间的j即可。这一步二分查找即可
//  复杂度O(26*26*logn)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), res = 0;
        vector<int> v[26];
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (v[i].empty() || v[j].empty()) continue;
                int low = v[i][0], high = v[i].back();
                if (low == high) continue;
                auto it = upper_bound(v[j].begin(), v[j].end(), low);
                if (it != v[j].end()) {
                    if (*it < high) res++;
                }
            }
        }
        return res;
    }
};
