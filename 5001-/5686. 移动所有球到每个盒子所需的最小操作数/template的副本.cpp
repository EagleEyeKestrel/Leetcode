//
//  main.cpp
//  数据量千级别，暴力就能过
//  如果不暴力的话，可以分两次遍历处理，第一次从左往右计，维护移动所有小球的开销
//  第二次再从右往左遍历，两次的加起来即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (boxes[j] == '1') tmp += abs(j - i);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
