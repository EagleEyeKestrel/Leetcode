//
//  main.cpp
//  可以直接统计一下。如果要空间O(1)可以这样：
//  在arr[i]可以算出之前缺失了多少数，如果发现大于等于k了，那么可以求出缺的第k个
//  如果始终未超过k，可以求出那一定是k + arr.size()
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            int lost = arr[i] - (i + 1);
            if(lost >= k) {
                return arr[i] - (lost - k) - 1;
            }
        }
        return k + arr.size();
    }
};
