//
//  main.cpp
//  可以边遍历边删
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char c: s) {
            if (!res.empty() && (res.back() == c + 'a' - 'A' || res.back() == c + 'A' - 'a')) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};
