//
//  main.cpp
//  基础的mp匹配，先算出p数组，然后进行模式匹配
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) return 0;
        int p[n + 1];
        p[0] = 0, p[1] = 0;
        for (int i = 1; i < n; i++) {
            int j = p[i];
            while (j && needle[j] != needle[i]) j = p[j];
            p[i + 1] = needle[j] == needle[i] ? j + 1 : 0;
        }
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j && haystack[i] != needle[j]) j = p[j];
            if (haystack[i] == needle[j]) j++;
            if (j == n) return i - n + 1;
        }
        return -1;
    }
};
