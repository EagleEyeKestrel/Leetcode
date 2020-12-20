//
//  main.cpp
//  比赛的时候肯定用哈希表方便。双指针的话，一定要注意arr可以有0或者负数！
//  有0的话，l不能等于r
//  有负数的话，这里采用对绝对值直接排序
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size(), l = 0;
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for (int r = 0; r < n; r++) {
            while (abs(arr[l] * 2) < abs(arr[r])) l++;
            if (l < r && arr[l] * 2 == arr[r]) return true;
        }
        return false;
    }
};
