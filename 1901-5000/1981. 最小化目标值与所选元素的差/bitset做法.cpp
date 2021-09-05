//
//  main.cpp
//  bitset做法，很厉害，放在这边记录一下大佬的做法
//  Copyright © 2021 ji luyang. All rights reserved.
//

const int N = 100, M = 5000;

bitset<M>  f[N];

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& a, int target) {
        bitset<M> b;
        b.set(0);
        for (int i = 0; i < a.size(); ++i){
            bitset<M> c;
            for (auto x: a[i])
                c |= b << x;
            b = c;
        }
        int ans = M;
        for (int i = 0; i < M; ++i)
            if (b[i])
                ans = min(ans, abs(i - target));
        return ans;
    }
};
