//
//  main.cpp
//  放进去1，-1，2，-2这样，如果是奇数个，放个0进去就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n % 2) res.push_back(0);
        for(int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};
