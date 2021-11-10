//
//  main.cpp
//  比较简单的构造题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        vector<int> res(n);
        int sum = mean * (m + n), num = n;
        for (int x: rolls) sum -= x;
        if (sum > 6 * n || sum < n) return {};
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 6; j++) {
                if (sum - j >= num - 1 && sum - j <= 6 * (num - 1)) {
                    res[i] = j;
                    sum -= j;
                    num--;
                    break;
                }
            }
        }
        return res;
    }
};
