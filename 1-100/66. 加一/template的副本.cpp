//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        int i = n - 1, d = 0;
        while (i >= 0) {
            digits[i] += d;
            d = digits[i] / 10;
            digits[i] %= 10;
            if (!d) break;
            i--;
        }
        if (d) digits.insert(digits.begin(), d);
        return digits;
    }
};
