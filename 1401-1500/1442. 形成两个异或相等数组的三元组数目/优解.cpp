//
//  main.cpp
//  巧妙，异或和相等，说明两个异或和的异或是0 啊
//  所以穷举i和k就行，只要k>i，异或和为0就行
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(),res = 0;
        for(int i = 1; i <= n; i++) {
            int now = arr[i - 1];
            for(int k = i + 1; k <= n; k++) {
                now = now ^ arr[k - 1];
                if(!now) {
                    res += k - i;
                }
            }
        }
        return res;
    }
};
