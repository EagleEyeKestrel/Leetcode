//
//  main.cpp
//  通过率最低的一道字符串，居然一次过了
//  不难，主要是代码细节。考虑取s的前一半不动/加一/减一翻转拼接，看之后的情况
//  额外处理一下边界
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long f(string s) {
        long long res = 0;
        for (char c: s) res = res * 10 - '0' + c;
        return res;
    }
    //  g取s的前一半，然后做成回文
    string g(string s) {
        int l = s.size();
        string spre = s.substr(0, l / 2 + l % 2);
        string slast = s.substr(0, l / 2);
        reverse(slast.begin(), slast.end());
        return spre + slast;
    }
    string nearestPalindromic(string n) {
        int l = n.size();
        if (l == 1) return to_string(stoi(n) - 1);
        string s1 = g(n);
        //  s99和s101是边界情况，如果n的前一半是100..或者999，考虑比n小的最大的999...和比n大的最小的10..01加入v
        string s99, s101 = "11";
        for (int i = 0; i < l - 1; i++) s99.push_back('9');
        for (int i = 0; i < l - 1; i++) s101.insert(s101.begin() + 1, '0');
        string spre = n.substr(0, l / 2 + l % 2);
        vector<string> v = { s1, s99, s101 };
        //  再考虑一下n的前半部分+1，-1后翻转拼接的结果
        string s2 = to_string(f(spre) - 1), s3 = to_string(f(spre) + 1);
        string ss2 = s2, ss3 = s3;
        if (l % 2) ss2 = ss2.substr(0, l / 2), ss3 = ss3.substr(0, l / 2);
        reverse(ss2.begin(), ss2.end());
        reverse(ss3.begin(), ss3.end());
        s2 += ss2, s3 += ss3;
        string res = "0";
        v.push_back(s2), v.push_back(s3);
        for (auto &s: v) {
            if (s == n) continue;
            if (abs(f(s) - f(n)) < abs(f(res) - f(n)) || abs(f(s) - f(n)) == abs(f(res) - f(n)) && f(s) < f(res)) res = s;
        }
        return res;
    }
};
