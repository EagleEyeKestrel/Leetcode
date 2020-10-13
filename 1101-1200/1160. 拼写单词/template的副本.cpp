//
//  main.cpp
//  cnt记录chars用的字母，然后tmp里去看是否够用
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c: chars) cnt[c - 'a']++;
        int res = 0;
        for(string& word: words) {
            int tmp[26];
            memcpy(tmp, cnt, sizeof(cnt));
            int flag = 1;
            for(int j = 0; j < word.size(); j++) {
                if(tmp[word[j] - 'a'] <= 0) {
                    flag = 0;
                    break;
                }
                tmp[word[j] - 'a']--;
            }
            if(flag) res += word.size();
        }
        return res;
    }
};
