//
//  main.cpp
//  双指针
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mid = arr[(n - 1) / 2], l = 0, r = n - 1;
        while(k--) {
            if (mid - arr[l] > arr[r] - mid) {
                res.push_back(arr[l++]);
            } else {
                res.push_back(arr[r--]);
            }
        }
        return res;
    }
};
