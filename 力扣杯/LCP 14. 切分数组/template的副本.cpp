//
//  main.cpp
//  wyh当时的思路，反正我是想不到。。
//  f[i]表示切分0-i的结果，最少切成几段
//  比较厉害的是g。g[i][j]表示 0-i里，最后一段的素因子是j，最少切分成多少段。最后一段是开的，也就是说以j开头，但是不知道在哪里结束。。
//  f[i]=min{g[i-1][p]}
//  对nums[i]所有因子p g[i][p]=min(g[i-1][p],f[i-1]+1)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minf[1000010], prime[1000010];
    void pre() {
        memset(minf, 0, sizeof(minf));
        for (int i = 1; i <= 1e6; i++) prime[i] = 1;
        for (int i = 2; i <= 1e6; i++) {
            if (prime[i] == 0) continue;
            minf[i] = i;
            for (int j = i + i; j <= 1e6; j += i) {
                prime[j] = 0;
                if (minf[j] == 0) minf[j] = i;
            }
        }
    }
    int splitArray(vector<int>& nums) {
        int n = nums.size();
        pre();
        int f[n], g[1000010];
        f[0] = 1;
        for (int i = 1; i <= 1e6; i++) g[i] = INT_MAX;
        int tmp = nums[0];
        while (tmp > 1) {
            g[minf[tmp]] = 1;
            tmp /= minf[tmp];
        }
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            f[i] = f[i - 1] + 1;
            int ps[30];
            int sz = 0;
            while (num > 1) {
                int o = minf[num];
                while (num % o == 0) num /= o;
                ps[sz++] = o;
            }
            for (int k = 0; k < sz; k++) {
                f[i] = min(f[i], g[ps[k]]);
            }
            for (int k = 0; k < sz; k++) {
                g[ps[k]] = min(g[ps[k]], f[i - 1] + 1);
            }
        }
        return f[n - 1];
    }
};
