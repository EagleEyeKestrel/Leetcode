//
//  main.cpp
//  把arr排序，把每个数字有多少个，存在nums里
//  贪心处理，每次删数量最少的数字
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size(), now = 0;
        sort(arr.begin(), arr.end());
        int nums[100010];
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp++;
            if (i == n - 1 || arr[i] != arr[i + 1]) {
                nums[now++] = tmp;
                tmp = 0;
            }
        }
        sort(nums, nums + now);
        int res = now;
        for (int i = 0; i < now; i++) {
            if (k >= nums[i]) {
                k -= nums[i];
                res--;
            }
        }
        return res;
    }
};
