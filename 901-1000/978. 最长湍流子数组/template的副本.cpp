//
//  main.cpp
//  看似简单，其实很易错。。尤其是在比赛，等于的情况有点烦人，这里特殊处理了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 1, tmp = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                tmp = 1;
            } else if (arr[i] > arr[i - 1]) {
                if (i == 1 || arr[i - 1] < arr[i - 2]) tmp++;
                else tmp = 2;
            } else {
                if (i == 1 || arr[i - 1] > arr[i - 2]) tmp++;
                else tmp = 2;
            }
            res = max(res, tmp);
        }
        return res;
    }
};
