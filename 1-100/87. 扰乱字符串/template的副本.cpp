//
//  main.cpp
//  比较难的题
//  以前的思路是递归。边界条件是s1 == s2，然后可以通过长度不等/组成字母不一样快速排除
//  在长度相等且组成字母一样的条件下，穷举分割点，有两种情况可以组成扰乱，但这种方法在新的测试用例下超时
//  应该用dp(记忆化搜索，用a,b,l表示s1 s2的起始位置以及长度，用cache保存，内部思路还是差不多，但是多了记忆的过程)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string s, t;
    int cache[31][31][31];
    bool f(int a, int b, int l) {
        if (cache[a][b][l]) return cache[a][b][l] == 1;
        string ss = s.substr(a, l), tt = t.substr(b, l);
        if (ss == tt) {
            cache[a][b][l] = 1;
            return true;
        }
        string sss = ss, ttt = tt;
        sort(sss.begin(), sss.end());
        sort(ttt.begin(), ttt.end());
        if (sss != ttt) {
            cache[a][b][l] = -1;
            return false;
        }
        for (int i = 1; i < l; i++) {
            if (f(a, b, i) && f(a + i, b + i, l - i) || f(a, b + l - i, i) && f(a + i, b, l - i)) {
                cache[a][b][l] = 1;
                return true;
            }
        }
        cache[a][b][l] = -1;
        return false;
    }
    bool isScramble(string s1, string s2) {
        memset(cache, 0, sizeof(cache));
        s = s1, t = s2;
        return f(0, 0, s1.size());
    }
};

/*class Solution {
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
};*/
