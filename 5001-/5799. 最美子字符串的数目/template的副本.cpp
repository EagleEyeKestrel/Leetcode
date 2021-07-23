//
//  main.cpp
//  想了一会，但还好没卡太久。
//  开始的思路肯定是统计到word[i]为止所有字母的计数，但是想不到如何进一步优化
//  滑动窗口显然也不行
//  想到题目中其实只在意每个字母出现次数的奇偶性，所以从word开始的每个字符串可以状态压缩成一个数来处理
//  对于一个状态now，之前的相减的状态可以是now(每个都是偶数)，也可以穷举10个字母哪一个出现了奇数次 即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        unordered_map<int, int> mp;
        mp[0]++;
        int now = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            now = now ^ (1 << (word[i] - 'a'));
            res += mp[now];
            for (int j = 0; j < 10; j++) {
                res += mp[now ^ (1 << j)];
            }
            mp[now]++;
        }
        return res;
    }
};
