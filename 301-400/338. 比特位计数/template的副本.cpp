//
//  main.cpp
//  利用 i & (i - 1) 是删除最后一个 1 来递推
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};
