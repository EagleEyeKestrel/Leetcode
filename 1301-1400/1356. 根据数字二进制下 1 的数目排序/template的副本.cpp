//
//  main.cpp
//  __builtin_popcount内置函数，给出一个int的1的个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int va = __builtin_popcount(a);
            int vb = __builtin_popcount(b);
            if(va == vb) return a < b;
            return va < vb;
        });
        return arr;
    }
};
