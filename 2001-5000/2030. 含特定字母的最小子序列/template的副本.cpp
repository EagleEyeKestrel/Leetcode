//
//  main.cpp
//  类似于删掉k个数字的单调栈问题，多了一个限制条件。
//  注意不用一开始就维护大小为k。可以先大小大于k，然后再删
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        string res;
        vector<int> pos;
        int n = s.size(), now = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == letter) {
                pos.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int id = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
            int num = pos.size() - id;
            while (!res.empty() && res.back() > c) {
                if (res.size() - 1 + n - i < k) break;
                if (res.back() == letter && now - 1 + num < repetition) break;
                if (res.back() == letter) now--;
                res.pop_back();
            }
            res.push_back(c);
            if (c == letter) now++;
        }
        while (res.size() > k) {
            if (res.back() == letter) now--;
            res.pop_back();
        }
        for (int i = k - 1; i >= 0; i--) {
            if (now < repetition && res[i] != letter) {
                res[i] = letter;
                now++;
            }
        }
        return res;
    }
};
