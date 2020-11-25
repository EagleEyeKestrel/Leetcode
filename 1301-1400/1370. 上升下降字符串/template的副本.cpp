//
//  main.cpp
//  虽然是简单题，但这个就没必要真的一遍遍去搜字符串了，直接用cnt统计字符个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string sortString(string s) {
        string res = "";
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c: s) cnt[c - 'a']++;
        while(res.size() < s.size()) {
            for(int i = 0; i < 26; i++) {
                if(cnt[i]) {
                    res.push_back(i + 'a');
                    cnt[i]--;
                }
            }
            for(int i = 25; i >= 0; i--) {
                if(cnt[i]) {
                    res.push_back(i + 'a');
                    cnt[i]--;
                }
            }
        }
        return res;
    }
};
