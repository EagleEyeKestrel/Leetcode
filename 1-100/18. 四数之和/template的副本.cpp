//
//  main.cpp
//  排序之后，穷举前两个数，剩下两个数用双指针，O(n^3)
//  注意一下去重的技巧，每次比较和之前一个是否相同，同就continue
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4) return res;
        for(int i = 0; i < n - 3; i++) {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1, v = target - nums[i] - nums[j];
                while(l < r) {
                    if(l > j + 1 && nums[l] == nums[l - 1]) {
                        l++;
                        continue;
                    }
                    if(r < n - 1 && nums[r] == nums[r + 1]) {
                        r--;
                        continue;
                    }
                    if(nums[l] + nums[r] == v) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        continue;
                    } else if(nums[l] + nums[r] > v) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
