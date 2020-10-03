//
//  main.cpp
//  用前缀和可以轻易解决，每次算到一个前缀和看下之前有没有就可以了，哈希表存一下之前的前缀和
//  注意要特判一下k为0的情况
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(!k) {
            for(int i = 1; i < n; i++) {
                if(nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }
        int s[n + 1];
        s[0] = 0;
        unordered_map<int, int> m;
        m[0] = 0;
        for(int i = 1; i <= n; i++) {
            s[i] = (s[i - 1] + nums[i - 1]) % k;
            if(m.count(s[i]) && m[s[i]] < i - 1) return true;
            if(!m.count(s[i])) m[s[i]] = i;
        }
        return false;
    }
};
