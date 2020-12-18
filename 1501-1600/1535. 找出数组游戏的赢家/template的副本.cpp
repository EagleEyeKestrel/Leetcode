//
//  main.cpp
//  首先一个很显然的事情，arr所有数比了一遍后，如果还没找到答案，那最大数会始终在arr[0]，结果也是它
//  所以模拟一下第一轮即可
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int tmp = 0, maxv = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[0] < arr[i]) {
                tmp = 1;
                arr[0] = arr[i];
            } else {
                tmp++;
            }
            if (tmp >= k) return arr[0];
            maxv = max(maxv, arr[i]);
        }
        return maxv;
    }
};
