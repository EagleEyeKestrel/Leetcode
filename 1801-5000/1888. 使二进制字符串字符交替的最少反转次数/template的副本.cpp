//
//  main.cpp
//  想了一会，我的思路大概是这样
//  长度为偶数的情况，只需要和"0101..."和"1010..."两种比较一下即可，（因为如果执行一次操作一，对s的每个字符来说，比对的元素只是在不断切换，所以情况无外乎这二者之一）。结果分别记为cnt1, cnt2。
//  然后是长度为奇数的情况，每次执行操作一，新的cnt2(和"1010..."的字符距离)取决于旧的cnt1(和"0101..."的字符距离)，新的cnt1取决于旧的cnt2，可以如此更新，遍历一遍就可以得到最优解。
//  看了评论区，感觉更容易想的解法是滑动窗口。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minFlips(string s) {
        int res = INT_MAX, n = s.size(), cnt1 = 0, cnt2 = 0, newcnt1, newcnt2;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                s[i] == '1' ? cnt1++ : cnt2++;
            } else {
                s[i] == '1' ? cnt2++ : cnt1++;
            }
        }
        res = min(cnt1, cnt2);
        if (n % 2 == 0) return res;
        for (int i = 0; i < n; i++) {
            newcnt1 = s[i] == '1' ? cnt2 + 1 : cnt2 - 1;
            newcnt2 = s[i] == '1' ? cnt1 - 1 : cnt1 + 1;
            res = min(res, min(newcnt1, newcnt2));
            cnt1 = newcnt1, cnt2 = newcnt2;
        }
        return res;
    }
};
