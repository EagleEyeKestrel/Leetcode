//
//  main.cpp
//  想了一下，确实O(n2)就可以了
//  如果用res[i][j]表示以arr[i][j]结尾的最小下降路径和
//  arr[i][j]加的应该是res[i-1][minid]，其中minid是res[i-1]里的最小值。如果最小值的minid不是j，就取minid。如果是j，就取第二小的。
//  所以每次只需要记录每行最小的和，最小和的位置，以及第二小的和即可。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size(), res = INT_MAX;
        int fir = INT_MAX, sec = INT_MAX, firpos;
        for (int i = 0; i < n; i++) {
            if (arr[0][i] < fir) {
                fir = arr[0][i];
                firpos = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == firpos) continue;
            sec = min(sec, arr[0][i]);
        }
        for (int i = 1; i < n; i++) {
            int tmp[n];
            for (int j = 0; j < n; j++) {
                if (j != firpos) {
                    tmp[j] = fir + arr[i][j];
                } else {
                    tmp[j] = sec + arr[i][j];
                }
            }
            fir = INT_MAX, sec = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (tmp[j] < fir) {
                    fir = tmp[j];
                    firpos = j;
                }
            }
            for (int j = 0; j < n; j++) {
                if (j == firpos) continue;
                sec = min(sec, tmp[j]);
            }
        }
        return fir;
    }
};
