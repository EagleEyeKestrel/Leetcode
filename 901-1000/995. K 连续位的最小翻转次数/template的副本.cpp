//
//  main.cpp
//  贪心+差分
//  总体策略是从最左边一个0开始作为子数组的最左侧翻，这个操作会影响后面的元素，然后再继续翻
//  朴素的实现是O(n2)
//  但反转一个子数组，其实就是对[l,r]范围内的元素进行反转
//  用tmp表示当前是否需要翻转。vis标记每个子数组的r+1位置
//  每次翻转[l,r]，到了r+1的时候，tmp需要翻转一下。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), tmp = 0, res = 0;
        int vis[n + 1];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            tmp ^= vis[i];
            int val = A[i] ^ tmp;
            if (val) continue;
            if (i > n - K) return -1;
            tmp ^= 1;
            vis[i + K] ^= 1;
            res++;
        }
        return res;
    }
};
