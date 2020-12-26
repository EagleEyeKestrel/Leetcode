//
//  main.cpp
//  排序双指针。贪心分配，对每个孩子，给他满足的最小尺寸的饼。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int r = 0;
        for (int l = 0; l < m; l++) {
            while (r < n && s[r] < g[l]) r++;
            if (r >= n) return l;
            r++;
        }
        return m;
    }
};
