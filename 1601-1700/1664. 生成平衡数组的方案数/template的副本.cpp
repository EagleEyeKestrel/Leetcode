//
//  main.cpp
//  商汤第三题，属于中档题
//  1,2,3,...i-1,i,i+1,...n
//  可以发现删除i后，后面的奇偶性会发生变化。所以预处理一下前i段的奇数下标和odd[i](和even[i])（这里下标从1开始）
//  删掉i之后的就可以用 even[n]-even[i]表示。
//  第一次交上去500+ms，击败5%，寻思着奇怪重交了一次，300+ms，击败80+%。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int odd[n + 1], even[n + 1];
        odd[0] = 0;
        even[0] = 0;
        for(int i = 1; i <= n; i++) {
            odd[i] = odd[i - 1];
            even[i] = even[i - 1];
            if(i % 2) odd[i] += nums[i - 1];
            else even[i] += nums[i - 1];
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(even[i - 1] + odd[n] - odd[i] == odd[i - 1] + even[n] - even[i]) res++;
        }
        return res;
    }
};
