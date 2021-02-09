//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countSegments(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                res += (s[i] != ' ');
                continue;
            }
            if (s[i] != ' ' && s[i + 1] == ' ') res++;
        }
        return res;
    }
};
