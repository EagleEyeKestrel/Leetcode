//
//  main.cpp
//  二叉搜索树排列的关键，对于一个序列
//  第一个数一定是树根。然后左子树，右子树只要内部顺序固定，可以任意错开插入，对应c[x+y][x]
//  然后递归处理子树的方案数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int c[1024][1024];
    int mod = 1e9 + 7;
    void pre() {
        for (int i = 1; i <= 1000; i++) c[i][0] = 1, c[i][i] = 1;
        for (int i = 2; i <= 1000; i++) {
            for (int j = 1; j <= i; j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
    int dfs(vector<int>& nums) {
        if (nums.size() <= 1) return 1;
        vector<int> l, r;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }
        int x = l.size(), y = r.size();
        return (long long)c[x + y][x] * dfs(l) % mod * dfs(r) % mod;
    }
    int numOfWays(vector<int>& nums) {
        pre();
        return dfs(nums) - 1;
    }
};
