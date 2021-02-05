//
//  main.cpp
//  依次检查长度为1，2，...位置的字符，发现有不等的就退出
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int res = 0, n = strs.size();
        if (!n) return "";
        if (n == 1) return strs[0];
        while (1) {
            int flag = 1;
            for (int i = 1; i < n; i++) {
                if (res >= strs[i].size() || strs[i][res] != strs[0][res]) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
            res++;
            if (res == strs[0].size()) break;
        }
        return strs[0].substr(0, res);
    }
};
