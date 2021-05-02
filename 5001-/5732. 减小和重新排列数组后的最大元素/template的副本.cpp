//
//  main.cpp
//  贪心即可， 比较简单
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1] + 1) arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};
