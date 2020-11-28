//
//  main.cpp
//  肯定优先选最大的最大边，但最大的最大边需要次大的两条边加起来能和他构成三角形
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int res = 0, n = A.size();
        sort(A.begin(), A.end());
        for(int i = n - 1; i >= 2; i--) {
            if(A[i - 1] + A[i - 2] > A[i]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
};
