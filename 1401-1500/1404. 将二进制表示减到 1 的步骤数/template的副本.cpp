//
//  main.cpp
//  模拟
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    void add(string& s) {
        int n = s.size(), d = 1;
        for (int i = n - 1; i >= 0; i--) {
            s[i] += d;
            if (s[i] == '2') {
                s[i] = '0';
                d = 1;
            } else {
                d = 0;
            }
        }
        if (d) s.insert(s.begin(), '1');
    }
    int numSteps(string s) {
        int res = 0;
        while (s != "1") {
            if (s.back() == '1') add(s);
            else s.pop_back();
            res++;
        }
        return res;
    }
};
