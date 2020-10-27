//
//  main.cpp
//  暴力就能过，复杂度n2logn。虽然没什么意思，但是基本的复杂度分析不是应该会吗？
//  看到评论区好多人吐槽，但个人认为这是基本功吧
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> res;
        for(int k = 0; k < m; k++) {
            int tmp[512], sz = r[k] - l[k] + 1, flag = 1;
            for(int i = 0; i < sz; i++) {
                tmp[i] = nums[i + l[k]];
            }
            sort(tmp, tmp + sz);
            for(int i = 1; i < sz; i++) {
                if(tmp[i] - tmp[i - 1] != tmp[1] - tmp[0]) {
                    flag = 0;
                    break;
                }
            }
            res.push_back(flag);
        }
        return res;
    }
};
