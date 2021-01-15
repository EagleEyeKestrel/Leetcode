//
//  main.cpp
//  自定义排序
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string customSortString(string S, string T) {
        int s[128];
        for (int i = 0; i < S.size(); i++) s[S[i]] = i;
        sort(T.begin(), T.end(), [s](char a, char b) {
            return s[a] < s[b];
        });
        return T;
    }
};
