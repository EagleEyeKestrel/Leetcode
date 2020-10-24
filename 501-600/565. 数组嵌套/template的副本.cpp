//
//  main.cpp
//  从一个没走过的元素开始走，直到走一圈
//  怎么标记一个元素走没走过？当然用数组可以。但这里直接加上n就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < n) {
                int l = 0, tmp = i;
                while(nums[tmp] < n) {
                    l++;
                    nums[tmp] += n;
                    tmp = nums[tmp] % n;
                }
                res = max(res, l);
            }
        }
        return res;
    }
};
