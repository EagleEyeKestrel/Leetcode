//
//  main.cpp
//  我的解法，反正一种是转变成010101..即s[i]%2==i%2，另一种就是s[i]%2!=i%2
//  要注意两点，首先这种两种情况的题，之前的s已经改过了，后面就不能用了
//  另一方面，找j的时候还要满足s[j]!=s[i]，不能省掉
//  因为这两个问题耽搁了比较久的时间
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int res1 = 0, res2 = 0;
        string ss = s;
        for (int i = 0; i < n; i++) {
            if (s[i] % 2 == i % 2) {
                int nt = -1;
                for (int j = i + 1; j < n; j++) {
                    if (s[j] % 2 == j % 2 && s[j] != s[i]) {
                        nt = j;
                        break;
                    }
                }
                if (nt == -1) {
                    res1 = INT_MAX;
                    break;
                }
                swap(s[i], s[nt]);
                res1++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (ss[i] % 2 != i % 2) {
                int nt = -1;
                for (int j = i + 1; j < n; j++) {
                    if (ss[j] % 2 != j % 2 && ss[j] != ss[i]) {
                        nt = j;
                        break;
                    }
                }
                if (nt == -1) {
                    res2 = INT_MAX;
                    break;
                }
                swap(ss[i], ss[nt]);
                res2++;
            }
        }
        if (res1 == INT_MAX && res2 == INT_MAX) return -1;
        return min(res1, res2);
    }
};
