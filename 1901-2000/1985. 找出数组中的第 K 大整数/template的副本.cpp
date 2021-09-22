//
//  main.cpp
//  两次RE 涨教训了。。第一次知道比较函数里 等于要定义成false
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](string &sa, string &sb) {
            if (sa.size() == sb.size()) {
                if (sa < sb) return 1;
                return 0;
            }
            if (sa.size() < sb.size()) return 1;
            return 0;
        });
        return nums[n - k];
    }
};
