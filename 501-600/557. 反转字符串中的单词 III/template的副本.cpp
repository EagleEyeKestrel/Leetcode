//
//  main.cpp
//  用stringstream写的，奇慢无比啊
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        stringstream ss(s);
        while (getline(ss, tmp, ' ')) {
            reverse(tmp.begin(), tmp.end());
            if (res.size() == 0) res = tmp;
            else res = res + " " + tmp;
        }
        return res;
    }
};
