//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size(), res = 0, last = 0;
        for (auto &s: bank) {
            int sum = 0;
            for (char c: s) sum += c - '0';
            if (sum > 0) {
                res += sum * last;
                last = sum;
            }
        }
        return res;
    }
};