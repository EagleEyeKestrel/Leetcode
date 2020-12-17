//
//  main.cpp
//  哦，做完了看答案才发现更快的方法是异或！
//  恍然大悟，又是去找一个只出现一次的字符，不够敏感啊
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c: t) cnt[c - 'a']++;
        for (char c: s) cnt[c - 'a']--;
        for (int i = 0; i < 26; i++) if (cnt[i]) return i + 'a';
        return 0;
    }
};
