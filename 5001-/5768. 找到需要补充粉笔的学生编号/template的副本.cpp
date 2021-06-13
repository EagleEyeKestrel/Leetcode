//
//  main.cpp
//  没啥难度，注意数据范围，以及需要先模一下s
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n = chalk.size(), s = 0;
        for (int x: chalk) s += x;
        k %= s;
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            if (tmp + chalk[i] > k) return i;
            tmp += chalk[i];
        }
        return n - 1;
    }
};
