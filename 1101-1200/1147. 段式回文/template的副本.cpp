//
//  main.cpp
//  开始想用dp解法，怎么想都想不到。后来想想，发现这应该是可贪心的
//  要分成尽可能多的部分，直接贪心处理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int l = 0, r = n - 1, res = 0;
        string s1, s2;
        while (l < r) {
            s1.push_back(text[l]);
            s2.insert(s2.begin(), text[r]);
            if (s1 == s2) {
                res += 2;
                s1.clear();
                s2.clear();
            }
            l++, r--;
        }
        if (s1.size()) res++;
        else if (l == r) res++;
        return res;
    }
};
