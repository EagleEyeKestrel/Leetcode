//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for (int i = 0; i + m * k - 1 < n; i++) {
            int flag = 1;
            for (int start = 0; start < m; start++) {
                for (int j = start; j < start + k * m; j += m) {
                    if (arr[i + j] != arr[i + start]) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) return true;
        }
        return false;
    }
};
