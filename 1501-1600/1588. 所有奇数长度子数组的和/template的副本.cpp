//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0, n = arr.size();
        int s[n + 1];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + arr[i - 1];
        for(int i = 1; i <= n; i += 2) {
            for(int j = i; j <= n; j++) {
                res += s[j] - s[j - i];
            }
        }
        return res;
    }
};
