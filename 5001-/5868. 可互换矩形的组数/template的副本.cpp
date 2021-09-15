//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<long long, int> mp;
        for (auto &pi: rectangles) {
            int k = gcd(pi[0], pi[1]);
            pi[0] /= k, pi[1] /= k;
            if (mp.count(100001ll * pi[0] + pi[1])) mp[100001ll * pi[0] + pi[1]]++;
            else mp[100001ll * pi[0] + pi[1]] = 1;
        }
        long long res = 0;
        for (auto [key, value]: mp) {
            if (value > 1) {
                res += (long long)value * (value - 1) / 2;
            }
        }
        return res;
    }
};
