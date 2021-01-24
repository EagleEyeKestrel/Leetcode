//
//  main.cpp
//  比较难的题
//  大体思路是递归。边界条件是s1 == s2，然后可以通过长度不等/组成字母不一样快速排除
//  在长度相等且组成字母一样的条件下，穷举分割点，有两种情况可以组成扰乱
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        int n = s1.size();
        for (int i = 1; i < n; i++) {
            string s11 = s1.substr(0, i), s12 = s1.substr(i);
            string s21 = s2.substr(0, i), s22 = s2.substr(i);
            string s23 = s2.substr(0, n - i), s24 = s2.substr(n - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            if (isScramble(s11, s24) && isScramble(s12, s23)) return true;
        }
        return false;
    }
};
