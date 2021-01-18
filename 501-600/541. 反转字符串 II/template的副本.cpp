//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, n = s.size();
        while (i < n) {
            if (n - i < k) {
                reverse(s.begin() + i, s.end());
                break;
            }
            reverse(s.begin() + i, s.begin() + i + k);
            i += 2 * k;
        }
        return s;
    }
};
