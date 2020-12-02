//
//  main.cpp
//  水题，最基本的滑动窗口
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), tmp = 0, res = 0;
        for(int r = 0; r < n; r++) {
            tmp += arr[r];
            if(r >= k - 1) {
                if(r >= k) tmp -= arr[r - k];
                if(tmp >= threshold * k) res++;
            }
        }
        return res;
    }
};
