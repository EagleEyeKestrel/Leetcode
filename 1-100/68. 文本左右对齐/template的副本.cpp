//
//  main.cpp
//  很无聊的题，纯粹去实现各种规则，夯实code基础。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), i = 0;
        vector<string> res;
        while (i < n) {
            int nowlength = words[i].size(), j = i;
            while (j + 1 < n && nowlength + words[j + 1].size() + 1 <= maxWidth) {
                j++;
                nowlength += words[j].size() + 1;
            }
            if (j == n - 1) {
                string tmp = words[i];
                for (int k = i + 1; k <= j; k++) {
                    tmp.push_back(' ');
                    tmp += words[k];
                }
                while (tmp.size() < maxWidth) tmp.push_back(' ');
                res.push_back(tmp);
                break;
            }
            int cnt = j - i + 1, lsum = 0;
            for (int k = i; k <= j; k++) lsum += words[k].size();
            int spaces = maxWidth - lsum;
            if (cnt == 1) {
                string tmp = words[i];
                while (tmp.size() < maxWidth) tmp.push_back(' ');
                res.push_back(tmp);
                i++;
                continue;
            }
            string tmp = words[i];
            int remain = spaces % (cnt - 1);
            for (int k = i + 1; k <= j; k++) {
                int d = spaces / (cnt - 1) + (k - i <= remain);
                while (d--) tmp.push_back(' ');
                tmp += words[k];
            }
            res.push_back(tmp);
            i = j + 1;
        }
        return res;
    }
};
