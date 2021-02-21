//
//  main.cpp
//  只有两种可能，不同的字符数只可能是0或2
//  如果是0，那么一旦有重复的字符就可以满足
//  如果是2，那么就看对应两个字符是否相等
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        vector<int> diff;
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        int maxv = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                diff.push_back(i);
            }
            cnt[A[i]]++;
            maxv = max(maxv, cnt[A[i]]);
        }
        if (diff.empty()) return maxv > 1;
        if (diff.size() != 2) return false;
        return A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};
