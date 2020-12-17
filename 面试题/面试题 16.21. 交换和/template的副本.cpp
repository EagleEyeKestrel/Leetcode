//
//  main.cpp
//  老题目了，反正就是看两个数组有没有相差为d的元素，可以用哈希，也可以排序双指针
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = 0, sum2 = 0, n1 = array1.size(), n2 = array2.size();
        for (int num: array1) sum1 += num;
        for (int num: array2) sum2 += num;
        if ((sum1 - sum2) % 2) return {};
        int d = (sum1 - sum2) / 2;
        unordered_set<int> s(array2.begin(), array2.end());
        for (int num: array1) {
            if (s.count(num - d)) {
                return { num, num - d };
            }
        }
        return {};
    }
};
