//
//  main.cpp
//  印象深刻的挺难想的单调栈
//  third存储a_k的值，要让third尽可能大。只要被弹出，就更新third，被弹出说明左边有数更大
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top(); st.pop();
            }//栈顶是nums[i]右边第一个比nums[i]大的数
            st.push(nums[i]);
        }
        return false;
    }
};
