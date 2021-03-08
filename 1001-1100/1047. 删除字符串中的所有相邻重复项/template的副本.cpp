//
//  main.cpp
//  贪心弹
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (char c: S) {
            if (!res.empty() && c == res.back()) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};
