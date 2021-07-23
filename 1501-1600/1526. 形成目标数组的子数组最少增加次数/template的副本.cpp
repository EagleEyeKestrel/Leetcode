//
//  main.cpp
//  具体证明见零神的题解。很巧妙
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0], n = target.size();
        for (int i = 1; i < n; i++) res += max(0, target[i] - target[i - 1]);
        return res;
    }
};
