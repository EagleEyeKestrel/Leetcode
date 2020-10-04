//
//  main.cpp
//  格雷编码的公式
//  很难想，但是可以证明这个公式得到的数，每次二进制数只会有一位发生变化（分奇偶讨论就行
//  在第209场周赛的最后一题发挥了重要作用。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < 1 << n; i++) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
