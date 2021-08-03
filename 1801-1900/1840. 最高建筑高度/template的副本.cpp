//
//  main.cpp
//  可以看零神的题解
//  每个楼的高度限制分为两部分，一部分受左边所有楼的制约，一部分受右边所有楼的制约，都小于等于一个值
//  这个值可以边遍历边得到前面所有楼综合的限制值。然后对于相邻两栋楼i,j之间的最高高度h
//  h-h[i]+h-h[j]<=j-i，可以得到h的最大值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({ 1, 0 });
        sort(restrictions.begin(), restrictions.end());
        if (restrictions.back()[0] != n) {
            restrictions.push_back({ n, n - 1 });
        }
        int m = restrictions.size();
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + ((restrictions[i + 1][0] - restrictions[i][0])));
        }
        int res = 0;
        for (int i = 0; i < m - 1; i++) {
            int tmp = (restrictions[i + 1][0] - restrictions[i][0] + restrictions[i][1] + restrictions[i + 1][1]) / 2;
            res = max(res, tmp);
        }
        return res;
    }
};
