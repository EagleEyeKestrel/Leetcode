//
//  main.cpp
//  不错的题目
//  显然问号的个数只能是奇数。从只有两个问号的情况开始考虑
//  如果问号在两边，不难证明如果要bob赢，那必须两边剩下的数字和要相等
//  如果问号在同侧，不难证明这一侧的数字和要比另一侧少9，且只能是9
//  那么扩展到多个括号的情况，假设左边一半有m个问号，右边一半有n个
//  那么左边的数字和s1，右边的数字和s2应该有关系s1+9*(x-y)/2==s2时，bob胜利
//  要注意不能直接用两个size相减。。因为size默认类型是unsigned的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool sumGame(string num) {
        vector<int> v1, v2;
        int n = num.size(), s1 = 0, s2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') v1.push_back(i);
            else s1 += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') v2.push_back(i);
            else s2 += num[i] - '0';
        }
        if ((v1.size() + v2.size()) % 2) return true;
        int x = v1.size(), y = v2.size();
        return s1 + 9 * (x - y) / 2 != s2;
    }
};
