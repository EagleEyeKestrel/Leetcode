//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string res;
        for (auto s: words) {
            string t = s;
            reverse(t.begin(), t.end());
            if (t == s) {
                res = s;
                break;
            }
        }
        return res;
    }
};
