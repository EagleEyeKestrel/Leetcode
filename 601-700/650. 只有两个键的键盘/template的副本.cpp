//
//  main.cpp
//  等价于质因数分解。每个质因数需要copy一次，paste factors[i] - 1次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSteps(int n) {
        vector<int> factors;
        int now = n, res = 0;
        for(int i = 2; i <= n; i++) {
            while(now % i == 0) {
                now /= i;
                factors.push_back(i);
            }
            if(now == 1) break;
        }
        for(int i = 0; i < factors.size(); i++) {
            res += factors[i] - 1;
        }
        return res + factors.size();
    }
};
