//
//  main.cpp
//  每次以.为界，计算.之前的数字大小
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0;
        while (i < m || j < n) {
            int a = 0, b = 0;
            while (i < m && version1[i] != '.') {
                a = a * 10 + version1[i] - '0';
                i++;
            }
            while (j < n && version2[j] != '.') {
                b = b * 10 + version2[j] - '0';
                j++;
            }
            i++, j++;
            if (a > b) return 1;
            if (a < b) return -1;
        }
        return 0;
    }
};
