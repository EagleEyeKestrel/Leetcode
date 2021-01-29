//
//  main.cpp
//  贪心
//  l统计还有几个残余的左括号
//  如果是右括号，先看有没有连续的两个，如果没有要添加一个。
//  另外看有没有残余的左括号了。最后的结果是res+2l，因为每个剩下的左括号要补2个右括号
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), l = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                l++;
            } else {
                int flag = 0;
                if (i == n - 1 || s[i + 1] != ')') {
                    res++;
                    flag = 1;
                }
                if (!l) {
                    res++;
                } else {
                    l--;
                }
                if (!flag) i++;
            }
        }
        return res + 2 * l;
    }
};
