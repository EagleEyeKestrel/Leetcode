//
//  main.cpp
//  确实可以并查集，但没必要，把每个s，因为长度一样
//  可以把奇数索引组成的s1，偶数索引组成的s2排序，加起来，放入哈希表里，自动去重
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (string &a: A) {
            string s_odd, s_even;
            for (int i = 0; i < a.size(); i++) {
                if (i % 2) {
                    s_odd.push_back(a[i]);
                } else {
                    s_even.push_back(a[i]);
                }
            }
            sort(s_odd.begin(), s_odd.end());
            sort(s_even.begin(), s_even.end());
            s.insert(s_odd + s_even);
        }
        return s.size();
    }
};
