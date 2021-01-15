//
//  main.cpp
//  其实就是先找到第一个1，然后贪心的按开关即可
//  数一下一共有几段数字
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minFlips(string target) {
        int n = target.size(), res = 0;
        int first1 = -1, last1 = -1;
        for (int i = 0; i < n; i++) {
            if (target[i] == '1') {
                first1 = i;
                break;
            }
        }
        if (first1 == -1) return 0;
        for (int i = first1; i < n; i++) {
            if (i == n - 1 || target[i] != target[i + 1]) {
                res++;
            }
        }
        return res;
    }
};
