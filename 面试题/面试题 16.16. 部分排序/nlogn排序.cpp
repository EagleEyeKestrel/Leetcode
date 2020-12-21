//
//  main.cpp
//  第一次的解法，排序然后对比，时间很慢，空间O(n)，时间O(nlogn)，只击败了5%
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> v = array;
        sort(v.begin(), v.end());
        int l = -1, r = -1, n = array.size();
        for (int i = 0; i < n; i++) {
            if (v[i] != array[i]) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] != array[i]) {
                r = i;
                break;
            }
        }
        return {l, r};
    }
};

