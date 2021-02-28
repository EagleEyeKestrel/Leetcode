//
//  main.cpp
//  贪心就行，排序之后，看看加到哪个元素为止和最大
//  dp当然也可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size(), res = 0;
        sort(satisfaction.rbegin(), satisfaction.rend());
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j <= i; j++) {
                tmp += satisfaction[j] * (i + 1 - j);
            }
            res = max(res, tmp);
        }
        return res;
    }
};
