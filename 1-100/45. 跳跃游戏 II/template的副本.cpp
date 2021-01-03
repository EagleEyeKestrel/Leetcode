//
//  main.cpp
//  贪心，怎么贪心呢？
//  显然应该对于步数去贪心。假如第i步的范围已知，那么可以推出第i+1步的范围，就是i步里走出来的超过i最大范围的部分
//  所以这里对step累加，nowmax是第step步走完最大范围，premax是第step-1步走完最大范围
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, nowmax = 0, premax = -1;
        if (!n) return 0;
        while (1) {
            if (nowmax >= n - 1) return step;
            int nextmax = 0;
            for (int i = premax + 1; i <= nowmax; i++) {
                nextmax = max(nextmax, nums[i] + i);
            }
            premax = nowmax;
            nowmax = nextmax;
            step++;
        }
        return 0;
    }
};
