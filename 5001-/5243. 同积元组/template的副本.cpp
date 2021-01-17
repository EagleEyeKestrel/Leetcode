//
//  main.cpp
//  简单的数学题
//  找到一对(a,b) (c,d)，使得a*b=c*d后，这四个数的排列有八种
//  对于每个乘积，统计有cnt对数字。cnt对里选2对，然后乘以8
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        for (auto it: mp) {
            int cnt = it.second;
            res += cnt * (cnt - 1) * 4;
        }
        return res;
    }
};
