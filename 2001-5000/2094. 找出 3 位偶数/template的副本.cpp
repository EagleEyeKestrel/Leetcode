//
//  main.cpp
//  暴力，当然可以用cnt数组去优化一下，现在是百万，优化之后就是1000
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || i == k || j == k || digits[i] == 0) continue;
                    if (digits[k] & 1) continue;
                    int tmp = 100 * digits[i] + 10 * digits[j] + digits[k];
                    s.insert(tmp);
                }
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
