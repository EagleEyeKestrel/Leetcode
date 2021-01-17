//
//  main.cpp
//  看到题目就想到1类似于左括号，0类似于右括号
//  每次可以交换两个相邻的平衡括号串。
//  可以发现，如果有连续的平衡括号串abcd，对abcd直接排序就可以得到结果
//  如果对于(A)这样的括号串，就先把A排序，即递归处理。
//  f函数就是在递归处理。关键在于一串abcd，怎么递归处理a，或者说a的子问题是什么？
//  a是平衡括号串，那么a的开头一定是1，结尾一定是0，a的子问题就是挖掉开头和结尾
//  所以开始预处理一下所有括号对应平衡的位置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int a[60];
    void f(string& S, int l, int r) {
        if (l >= r) return;
        multiset<string> s;
        int now = l;
        while (now <= r) {
            int end = a[now];
            f(S, now + 1, end - 1);
            s.insert(S.substr(now, end - now + 1));
            now = end + 1;
        }
        now = l;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            string tmp = *it;
            for (char c: tmp) S[now++] = c;
        }
    }
    string makeLargestSpecial(string S) {
        int n = S.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (S[i] == '1') {
                v.push_back(i);
            } else {
                a[i] = v.back();
                a[v.back()] = i;
                v.pop_back();
            }
        }
        f(S, 0, n - 1);
        return S;
    }
};
