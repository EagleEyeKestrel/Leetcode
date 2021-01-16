//
//  main.cpp
//  统计不同的位置，按s1[i]是x还是y分类计数
//  比如 xxyyxyxyxx
//      xyyxyxxxyx
//  有三个x，三个y
//  (x,y)和(x,y) 或者(y,x) (y,x) 可以直接交换，一次交换解决两个不同的地方
//  最后至多剩下一个x和y，如果一个有另外一个没有那就不可能复原了。
//  如果刚好还有1个x 1个y，需要两次交换
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x = 0, y = 0, n = s1.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') x++;
                else y++;
            }
        }
        res = x / 2 + y / 2;
        x %= 2, y %= 2;
        if (x ^ y) return -1;
        return res + x + y;
    }
};
