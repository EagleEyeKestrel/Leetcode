//
//  main.cpp
//  二分答案，遍历验证的裸题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(vector<int>& nums, int mid, int maxOperations) {
        int n = nums.size();
        long long cnt = 0;
        for (int num: nums) {
            if (num % mid) cnt += num / mid;
            else cnt += num / mid - 1;
        }
        return cnt <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, mid, maxOperations)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
