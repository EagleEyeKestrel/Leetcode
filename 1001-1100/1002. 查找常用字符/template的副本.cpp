//
//  main.cpp
//  其实就是找所有字母出现次数的最小值
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c: A[0]) cnt[c - 'a']++;
        for(int i = 1; i < A.size(); i++) {
            int tmp[26];
            memset(tmp, 0, sizeof(tmp));
            for(char c: A[i]) tmp[c - 'a']++;
            for(int j = 0; j < 26; j++) {
                cnt[j] = min(cnt[j], tmp[j]);
            }
        }
        vector<string> res;
        for(int i = 0; i < 26; i++) {
            string str = "a";
            str[0] += i;
            for(int j = 0; j < cnt[i]; j++) {
                res.push_back(str);
            }
        }
        return res;
    }
};
