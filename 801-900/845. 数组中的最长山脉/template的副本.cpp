//
//  main.cpp
//  up[i]表示A[i]左边连续上升的长度，down表示A[i]右边连续下降的长度
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), res = 0;
        if(!n) return 0;
        int up[n], down[n];
        up[0] = 0;
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i - 1]) up[i] = up[i - 1] + 1;
            else up[i] = 0;
        }
        down[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
            else down[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};
