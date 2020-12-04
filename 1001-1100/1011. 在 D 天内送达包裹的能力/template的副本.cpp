//
//  main.cpp
//  二分查找+贪心，现在是非常非常基础的题目了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(vector<int>& weights, int mid, int D) {
        int res = 0, tmp = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > mid) return 0;
            if(tmp + weights[i] <= mid) {
                tmp += weights[i];
            } else {
                tmp = weights[i];
                res++;
            }
        }
        return res + 1 <= D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1, r = 50000000;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(weights, mid, D)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
