//
//  main.cpp
//  模拟删除就行了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l == r || s[l] != s[r]) break;
            int ll = l, rr = r;
            while (ll < rr && s[ll + 1] == s[ll]) ll++;
            if (ll == rr) return 0;
            while (rr > ll && s[rr - 1] == s[rr]) rr--;
            l = ll + 1, r = rr - 1;
        }
        return l <= r ? r - l + 1 : 0;
    }
};
