//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(!n) return vector<int>();
        int c1 = nums[0], c2 = nums[0], cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == c1) {
                cnt1++;
                continue;
            }
            if(nums[i] == c2) {
                cnt2++;
                continue;
            }
            if(cnt1 == 0) {
                c1 = nums[i];
                cnt1 = 1;
                continue;
            }
            if(cnt2 == 0) {
                c2 = nums[i];
                cnt2 = 1;
                continue;
            }
            cnt1--;
            cnt2--;
        }
        vector<int> res;
        cnt1 = 0, cnt2 = 0;
        for(int num: nums) {
            if(num == c1) cnt1++;
            else if(num == c2) cnt2++;
        }
        if(cnt1 > n / 3) res.push_back(c1);
        if(cnt2 > n / 3) res.push_back(c2);
        return res;
    }
};
