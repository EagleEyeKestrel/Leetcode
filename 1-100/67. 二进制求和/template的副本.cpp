//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size(), d = 0;
        string res;
        int i = m - 1, j = n - 1;
        while (i >= 0 || j >= 0) {
            int av = i >= 0 ? a[i] - '0' : 0;
            int bv = j >= 0 ? b[j] - '0' : 0;
            int v = av + bv + d;
            res.push_back(v % 2 + '0');
            d = v / 2;
            i--, j--;
        }
        if (d) res.push_back(d + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
