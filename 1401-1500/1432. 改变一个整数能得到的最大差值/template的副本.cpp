//
//  main.cpp
//  可以去算应该把什么数换成什么数，懒得想了，直接暴力解决了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int maxv = num, minv = num;
        for (int x = 0; x <= 9; x++) {
            for (int y = 0; y <= 9; y++) {
                string tmp = s;
                for (int i = 0; i < tmp.size(); i++) {
                    if (tmp[i] == x + '0') {
                        tmp[i] = y + '0';
                    }
                }
                if (tmp[0] == '0') continue;
                int v = stoi(tmp);
                maxv = max(maxv, v);
                minv = min(minv, v);
            }
        }
        return maxv - minv;
    }
};
