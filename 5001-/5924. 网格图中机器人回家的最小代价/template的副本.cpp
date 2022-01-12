//
//  main.cpp
//  我必须要骂几句这个题，不知道在考什么，毫无算法
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size(), n = colCosts.size();
        int sx = startPos[0], tx = homePos[0], sy = startPos[1], ty = homePos[1];
        int res = 0;
        if (sx > tx) {
            for (int i = sx - 1; i >= tx; i--) res += rowCosts[i];
        } else if (sx < tx) {
            for (int i = sx + 1; i <= tx; i++) res += rowCosts[i];
        }
        if (sy > ty) {
            for (int j = sy - 1; j >= ty; j--) res += colCosts[j];
        } else if (sy < ty) {
            for (int j = sy + 1; j <= ty; j++) res += colCosts[j];
        }
        return res;
    }
};
