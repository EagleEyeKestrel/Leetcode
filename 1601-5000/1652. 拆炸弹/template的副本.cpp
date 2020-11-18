//
//  main.cpp
//  可以n2暴力，也可以这样用前缀和优化成O(n)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(!k) return vector<int>(n, 0);
        int s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + code[i - 1];
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            int start = k > 0 ? (i + 1) % n : (i + k + n) % n;
            int end = k > 0 ? (i + k + n) % n : (i - 1 + n) % n;
            if(start <= end) {
                res[i] = s[end + 1] - s[start];
            } else {
                res[i] = s[n] - s[start] + s[end + 1];
            }
        }
        return res;
    }
};
