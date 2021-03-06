//
//  main.cpp
//  下一个更大元素 <=> 单调栈裸题，弄一个递减栈
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (!n) return {};
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[i % n] > nums[s.top()]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};
