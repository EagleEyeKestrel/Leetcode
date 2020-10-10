//
//  main.cpp
//  位向量法，用一个use[j]表示是否取nums[j]
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> res;
    void print(vector<int>& nums, int i, vector<int>& use, int n) {
        if(i == n) {
            vector<int> tmp;
            for(int j = 0; j < n; j++) {
                if(use[j]) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
            return ;
        }
        use[i] = 1;
        print(nums, i + 1, use, n);
        use[i] = 0;
        print(nums, i + 1, use, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> use(n, 0);
        print(nums, 0, use, n);
        return res;
    }
};
