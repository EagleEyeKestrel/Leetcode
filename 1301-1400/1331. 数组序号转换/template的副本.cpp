//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        unordered_map<int, int> m;
        vector<int> originArr = arr;
        sort(arr.begin(), arr.end());
        int id = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (i && arr[i] != arr[i - 1]) id++;
            m[arr[i]] = id;
        }
        for (int i = 0; i < originArr.size(); i++) {
            res.push_back(m[originArr[i]]);
        }
        return res;
    }
};
