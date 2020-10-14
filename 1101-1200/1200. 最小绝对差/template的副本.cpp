//
//  main.cpp
//  排序，然后看彼此之间的差就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size(), mind = 1e7;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] < mind) {
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
                mind = arr[i] - arr[i - 1];
            } else if(arr[i] - arr[i - 1] == mind) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};
