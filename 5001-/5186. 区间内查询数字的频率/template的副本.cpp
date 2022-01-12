//
//  main.cpp
//  比较简单，存每个数的索引即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class RangeFreqQuery {
public:
    vector<int> pos[10010];
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto &v = pos[value];
        int p1 = lower_bound(v.begin(), v.end(), left) - v.begin();
        int p2 = upper_bound(v.begin(), v.end(), right) - v.begin() - 1;
        return p2 - p1 + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
