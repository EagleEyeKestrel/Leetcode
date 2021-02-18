//
//  main.cpp
//  一次编辑，那么长度最多只能差1
//  如果长度相等，那么就检查不同的字符数目，不能超过1
//  如果长度差1，那么找到第一个不一样的地方，长的字符串删掉那个字符，然后继续
//  当然dp 编辑距离 肯定是通用解法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.size(), n = second.size();
        if (m > n) return oneEditAway(second, first);
        if (abs(m - n) > 1) return false;
        if (m == n) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (first[i] != second[i]) cnt++;
            }
            return cnt <= 1;
        }
        int now = 0;
        while (now < m && first[now] == second[now]) now++;
        if (now == m) return true;
        if (second[now + 1] != first[now]) return false;
        while (now < m && first[now] == second[now + 1]) now++;
        return now == m;
    }
};
