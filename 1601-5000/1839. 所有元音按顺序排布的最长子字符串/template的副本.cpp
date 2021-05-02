//
//  main.cpp
//  把相同的元音字母合并，合并后变成新的字符串s
//  v用来记录s中一个字符代表了重复出现多少次，比如aaaaeeiioouuu可以变成aeiou
//  v是{4,2,2,2,3}
//  然后只需看s里的aeiou即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size(), tmp = 0, res = 0;
        string s;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (!i || word[i] != word[i - 1]) tmp = 1;
            else tmp++;
            if (i == n - 1 || word[i] != word[i + 1]) {
                s.push_back(word[i]);
                v.push_back(tmp);
            }
        }
        for (int i = 4; i < s.size(); i++) {
            if (s[i] == 'u' && s[i - 1] == 'o' && s[i - 2] == 'i' && s[i - 3] == 'e' && s[i - 4] == 'a') {
                res = max(res, v[i] + v[i - 1] + v[i - 2] + v[i - 3] + v[i - 4]);
            }
        }
        return res;
    }
};
