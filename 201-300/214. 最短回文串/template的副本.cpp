//
//  main.cpp
//  要加前缀得到最短的回文串，也就是要找s最长的前缀回文串
//  s最长的回文前缀，可以用s + reverse_s，用mp去算到最长的长度
//  但是要注意，比如aabba这个例子，aabba abbaa这个串，最右边的特征值是6
//  不知道怎么处理。但实际上在中间加一个特殊符号就可以了，保证这个结果不会超过s的长度
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        string str = s + "." + s2;
        int p[100010];
        p[0] = 0, p[1] = 0;
        int n = str.size();
        for (int i = 1; i < n; i++) {
            int j = p[i];
            while (j && str[i] != str[j]) j = p[j];
            p[i + 1] = (str[i] == str[j] ? j + 1 : 0);
        }
        int l = p[n];
        if (l >= s.size()) return s;
        string add = s.substr(l);
        reverse(add.begin(), add.end());
        return add + s;
    }
};
