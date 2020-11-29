//
//  main.cpp
//  感慨颇深的一道题，这么简单居然没过
//  先开始想着统计每对和的个数，然后试每一个和，发现想不通
//  然后就想到了差分。对于一组数(a,b)，用0次/1次/2次操作，可以得到不同的范围
//  这样对0-200000所有的数，用差分累计，可以知道要得到这个和需要的操作次数
//  关键在于对(a,b)计算的时候，一直不知道b>limit的情况如何处理
//  因为2次操作的范围是[2,2limit] 一次的范围[a+1,b+limit]，中间还有空档
//  比赛结束才看到条件，limit >= nums[i] 恒成立！ 根本不用考虑
//  本来应该是最快的思路，被没看到条件给搞炸了。。哎
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int sum[200010];
        memset(sum, 0, sizeof(sum));
        int maxv = INT_MAX, res = INT_MAX;
        for(int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);
            if(b <= limit) {
                sum[a + b]--;
                sum[a + b + 1]++;
                sum[1 + a]--;
                sum[limit + b + 1]++;
                sum[2] += 2;
                maxv = min(maxv, limit + limit);
            }
        }
        for(int i = 2; i <= maxv; i++) {
            sum[i] += sum[i - 1];
            res = min(res, sum[i]);
        }
        return res;
    }
};
