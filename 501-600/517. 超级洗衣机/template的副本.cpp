//
//  main.cpp
//  这题是真的想不到，时隔一年还是不会
//  还是参考了评论区置顶的思路。不同的是，对于当前值和目标值的差diff
//  如果diff>0，那一定需要diff次移动，如果diff<=0，一次最多接受两个，那至少需要-(diff+1)/2次移动
//  但是如果直接是max(abs(cnt), diff)也是可以过的，这里不知道为什么
//  直观上，当最大值不是取到abs(cnt)的时候
//  如果cnt为负，说明一定要从右边传过来-cnt个，这个应该必须要取到至少-cnt
//  如果cnt为正，比如0 3 0的情况，这里中间和均值的差值是2，但累加的cnt是1
//  说明忽略了这个点既要向右又要向左发的情况，自然diff是正的时候会出现最大值不取abs(cnt)的情况
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size(), sum = 0;
        for(int machine: machines) sum += machine;
        if(sum % n) return -1;
        int res = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            int diff = machines[i] - sum / n;
            cnt += diff;
            int val = diff >= 0 ? diff : -(diff + 1) / 2;
            res = max(res, max(abs(cnt), val));
        }
        return res;
    }
};
