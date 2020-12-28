//
//  main.cpp
//  这题比第一题还简单。。但是！要注意都用int会溢出，WA了一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), tmp = customers[0][0];
        double res = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i][0] >= tmp) {
                res += customers[i][1];
                tmp = customers[i][0] + customers[i][1];
            } else {
                res += tmp + customers[i][1] - customers[i][0];
                tmp = tmp + customers[i][1];
            }
        }
        return res / n;
    }
};
