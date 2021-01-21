//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int m = num1.size(), n = num2.size();
        int i = m - 1, j = n - 1, d = 0;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i] - '0' : 0;
            int b = j >= 0 ? num2[j] - '0' : 0;
            int v = a + b + d;
            res.push_back(v % 10 + '0');
            d = v / 10;
            i--, j--;
        }
        if (d) res.push_back(d + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
