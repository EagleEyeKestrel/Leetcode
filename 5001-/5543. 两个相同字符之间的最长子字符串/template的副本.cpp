//
//  main.cpp
//  比赛的时候为了简洁性，反而可能直接穷举ij更好
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int first[26], last[26];
        memset(first, 0, sizeof(first));
        memset(last, 0, sizeof(last));
        for(int i = 0; i < s.size(); i++) {
            if(!first[s[i] - 'a']) {
                first[s[i] - 'a'] = i + 1;
            }
            last[s[i] - 'a'] = i + 1;
        }
        int res = -1;
        for(int i = 0; i < 26; i++) {
            if(first[i] != last[i]) res = max(res, last[i] - first[i] - 1);
        }
        return res;
    }
};
