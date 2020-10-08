//
//  main.cpp
//  存储之前最大的A[i] + i即可
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int res = INT_MIN;
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size(), premax = A[0];
        for(int j = 1; j < n; j++) {
            res = max(res, A[j] - j + premax);
            premax = max(premax, A[j] + j);
        }
        return res;
    }
};
