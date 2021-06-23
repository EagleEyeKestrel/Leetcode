//
//  main.cpp
//  第一次遇到，最后一题居然是中等？？
//  突破点在于nums[i]的数据范围很小，不超过100
//  自然想到遍历数据范围进行统计
//  s[i][j]表示前i 个元素里j的个数，然后对于每个query，可以得到大小为100的数字统计
//  自然就可以得到结果了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int s[n][101];
        memset(s, 0, sizeof(s));
        s[0][nums[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= 100; j++) s[i][j] = s[i - 1][j];
            s[i][nums[i]]++;
        }
        vector<int> res;
        for (auto &q: queries) {
            int tmp[101], b[101];
            if (q[0] == 0) for (int i = 1; i <= 100; i++) tmp[i] = s[q[1]][i];
            else for (int i = 1; i <= 100; i++) tmp[i] = s[q[1]][i] - s[q[0] - 1][i];
            int sz = 0, ans = INT_MAX;
            for (int i = 1; i <= 100; i++) {
                if (tmp[i]) {
                    b[sz++] = i;
                }
            }
            if (sz == 1) {
                res.push_back(-1);
                continue;
            }
            for (int i = 0; i < sz - 1; i++) ans = min(ans, b[i + 1] - b[i]);
            res.push_back(ans);
        }
        return res;
    }
};
