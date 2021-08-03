//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getLucky(string s, int k) {
        string res;
        for (char c: s) {
            res = res + to_string(c - 'a' + 1);
        }
        int ans;
        while (k--) {
            ans = 0;
            for (char c: res) ans += c - '0';
            res = to_string(ans);
        }
        return ans;
    }
};
