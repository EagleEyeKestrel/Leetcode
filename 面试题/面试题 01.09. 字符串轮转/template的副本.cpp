//
//  main.cpp
//  用了mp来做，s1+s2找到最后一个位置最大的特征值l,然后从l往后检查
//  如果能调stl，可以看s1+s1是否包含s2即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f[200010];
    bool isFlipedString(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m != n) return false;
        if (m < 2) return s1 == s2;
        string s = s1 + s2;
        f[0] = 0, f[1] = 0;
        for (int i = 1; i < s.size(); i++) {
            int j = f[i];
            while (j && s[i] != s[j]) j = f[j];
            f[i + 1] = (s[i] == s[j] ? j + 1 : 0);
        }
        int l = f[s.size()];
        for (int i = 0; i < s1.size() - l; i++) {
            if (s1[i + l] != s2[i]) return false;
        }
        return true;
    }
};
