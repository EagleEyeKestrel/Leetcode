//
//  main.cpp
//  比较简单，把原式变个形即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    //nums[j]-rev(nums[j])==nums[i]-rev(nums[i])
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), res = 0, mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int tmp = nums[i] - stoi(s);
            res = (res + mp[tmp]) % mod;
            mp[tmp]++;
        }
        return res;
    }
};
