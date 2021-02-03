//
//  main.cpp
//  把每个字符串处理成<字符，计数>的序列，然后依次检查即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<pair<char, int>> f(string& s) {
        int tmp = 0;
        vector<pair<char, int>> res;
        for (int i = 0; i < s.size(); i++) {
            if (!i || s[i] != s[i - 1]) tmp = 1;
            else tmp++;
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                res.push_back(make_pair(s[i], tmp));
            }
        }
        return res;
    }
    int expressiveWords(string S, vector<string>& words) {
        auto target = f(S);
        int res = 0;
        for (auto & word: words) {
            auto v = f(word);
            if (v.size() != target.size()) continue;
            int flag = 1;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].first != target[i].first || v[i].second > target[i].second || target[i].second > v[i].second && target[i].second < 3) {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
