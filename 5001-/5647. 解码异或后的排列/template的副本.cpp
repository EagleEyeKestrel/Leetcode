//
//  main.cpp
//  想了一会没思路，不知道怎么求排列的第一个元素。
//  突然发现题目中强调了n为奇数，那么估计是个关键
//  继而想到了对于a[1], a[2], ... a[n]，
//  可以求出a[1] ^ a[2] ^ ... ^ a[n-2] ^ a[n-1]
//  继而求出a[n]，然后就简单了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int sum = 0, tmp = 0;
        int n = encoded.size() + 1;
        for (int i = 1; i <= n; i++) sum ^= i;
        vector<int> res(n);
        for (int i = 0; i < n - 1; i += 2) tmp ^= encoded[i];
        res[n - 1] = sum ^ tmp;
        for (int i = n - 2; i >= 0; i--) {
            res[i] = res[i + 1] ^ encoded[i];
        }
        return res;
    }
};
