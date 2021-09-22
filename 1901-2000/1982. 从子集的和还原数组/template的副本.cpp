//
//  main.cpp
//  不会...去看题解吧
//  先处理非负情况，非负的情况是比较经典的问题
//  关键在于求到非负之后，直接找到一个子集mask，使得mask的和等于bias即可
//  这样 加上-bias之后的子集和 和真正的子集和 就是一一对应的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        int bias = 0;
        for (int x: sums) bias = min(bias, x);
        multiset<int> s;
        for (int x: sums) s.insert(x - bias);
        vector<int> res;
        s.erase(s.begin());
        for (int i = 0; i < n; i++) {
            int val = *(s.begin()), sz = res.size();
            res.push_back(val);
            for (int mask = 0; mask < 1 << sz; mask++) {
                int sum = 0;
                for (int j = 0; j < sz; j++) {
                    if (mask >> j & 1) {
                        sum += res[j];
                    }
                }
                s.erase(s.find(val + sum));
            }
        }
        
        for (int mask = 0; mask < 1 << n; mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    sum += res[i];
                }
            }
            if (sum == -bias) {
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        res[i] = -res[i];
                    }
                }
                return res;
            }
        }
        return {};
    }
};
