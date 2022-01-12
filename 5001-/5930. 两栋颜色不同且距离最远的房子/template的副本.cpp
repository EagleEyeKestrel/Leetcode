//
//  main.cpp
//  可以想想如何做到O(n).其实也不难，贪心就可以了
//  如果两端相同，都是颜色a 那么最远的两个房子颜色必然包括a （如果是bc，肯定不如ab或者ca）
//  所以找到最远的b即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors.back()) return n - 1;
        int l = 0, r = n - 1;
        while (colors[l] == colors[0]) l++;
        while (colors[r] == colors.back()) r--;
        return max(n - 1 - l, r);
    }
};
