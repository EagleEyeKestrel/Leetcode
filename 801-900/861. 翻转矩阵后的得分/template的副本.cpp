//
//  main.cpp
//  贪心。显然第一列的权重最大，所以第一步是对每一行翻转，使得第一列都是1
//  然后，就不动行了，分析每一列。如果每一列的1比0少，那么进行翻转
//  自己想出来的，但不确定，结果居然是对的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; i++) {
            if(!A[i][0]) {
                for(int j = 0; j < n; j++) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        for(int j = 1; j < n; j++) {
            int one = 0, zero = 0;
            for(int i = 0; i < m; i++) {
                if(A[i][j]) one++;
                else zero++;
            }
            if(zero > one) {
                for(int i = 0; i < m; i++) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                tmp = 2 * tmp + A[i][j];
            }
            res += tmp;
        }
        return res;
    }
};
