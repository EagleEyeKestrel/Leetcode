//
//  main.cpp
//  穷举最后是A或者B变成全1，2，3，4，5，6 空间肯定最优，哈哈
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size(), res = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            int cntA = 0, cntB = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] == i) continue;
                else if (B[j] == i) cntA++;
                else {
                    cntA = INT_MAX;
                    break;
                }
            }
            for (int j = 0; j < n; j++) {
                if (B[j] == i) continue;
                else if (A[j] == i) cntB++;
                else {
                    cntB = INT_MAX;
                    break;
                }
            }
            res = min(res, min(cntA, cntB));
        }
        return res == INT_MAX ? -1 : res;
    }
};
