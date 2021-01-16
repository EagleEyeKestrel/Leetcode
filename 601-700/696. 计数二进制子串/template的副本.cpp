//
//  main.cpp
//  我的做法：统计当前的1/0有多少个
//  比如110011000，个数分别是2223，每次加上相邻两个的最小值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero = 0, one = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') zero++;
            else one++;
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                res += min(zero, one);
                if (s[i] == '1') zero = 0;
                else one = 0;
            }
        }
        return res;
    }
};
