//
//  main.cpp
//  贪心地去安排座位，注意用^1去表示是否是情侣的技巧
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), res = 0;
        for (int i = 0; i < n; i += 2) {
            if (row[i + 1] == (row[i] ^ 1)) continue;
            for (int j = i + 2; j < n; j++) {
                if (row[j] == (row[i] ^ 1)) {
                    swap(row[j], row[i + 1]);
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
