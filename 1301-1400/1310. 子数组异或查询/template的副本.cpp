//
//  main.cpp
//  和前缀和完全一样的思路，只不过以前+的逆运算是-，而异或的逆运算还是异或。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] ^ arr[i - 1];
        }
        vector<int> res;
        for (auto &q: queries) {
            res.push_back(s[q[1] + 1] ^ s[q[0]]);
        }
        return res;
    }
};
