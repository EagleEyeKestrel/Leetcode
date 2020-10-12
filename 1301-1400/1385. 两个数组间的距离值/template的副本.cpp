//
//  main.cpp
//  本来暴力就行了
//  这里稍微优化了一下
//  找到和arr1[i]最相近的两个元素就行了，优化成mlogn
//  差点WA一次，第一个if也要判断一下id < n，因为id可能处于arr2.end()
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0, m = arr1.size(), n = arr2.size();
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < m; i++) {
            int id = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            if(id < n && arr2[id] - arr1[i] <= d) continue;
            if(id && arr1[i] - arr2[id - 1] <= d) continue;
            res++;
        }
        return res;
    }
};
