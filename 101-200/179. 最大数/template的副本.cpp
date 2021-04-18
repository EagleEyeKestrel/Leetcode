//
//  main.cpp
//  关键是如何排序，可以联想冒泡排序，什么时候需要交换
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        string res;
        for (int num: nums) res += to_string(num);
        int now = 0;
        while (now + 1 < res.size() && res[now] == '0') now++;
        return res.substr(now);
    }
};
