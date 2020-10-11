//
//  main.cpp
//  很神奇，写完发现自己和一年前的代码几乎一样
//  一看知道肯定可以用dp解决，于是按大小排序，用个哈希表存储之前字符串的最长链
//  因为每个字符串的长度很短，所以选择枚举字符串切掉哪一个字符，然后如果map里有，就更新s[word]
//  复杂度O(16n)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> s;
        int res = 1;
        for(int i = 0; i < n; i++) {
            s[words[i]] = 1;
            if(words[i].size() == 1) {
                continue;
            }
            string word = words[i];
            for(int j = 1; j <= word.size(); j++) {
                string tmp = word.substr(0, j - 1) + word.substr(j);
                if(s.count(tmp)) {
                    s[word] = max(s[tmp] + 1, s[word]);
                }
            }
            res = max(res, s[word]);
        }
        return res;
    }
};
