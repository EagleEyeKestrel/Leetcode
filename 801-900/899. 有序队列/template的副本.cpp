//
//  main.cpp
//  K = 1显然
//  K >= 2可以证明S中任何两个位置可以进行交换。所以可以直接得到最优解
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K >= 2) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        int n = S.size();
        for (int i = 0; i < n; i++) {
            char c = S[0];
            S = S.substr(1);
            S.push_back(c);
            if (S < res) res = S;
        }
        return res;
    }
};
