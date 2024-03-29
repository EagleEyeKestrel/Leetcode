//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumMoves(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') {
                s[i] = 'O';
                if (i + 1 < n) s[i + 1] = 'O';
                if (i + 2 < n) s[i + 2] = 'O';
                res++;
            }
        }
        return res;
    }
};
