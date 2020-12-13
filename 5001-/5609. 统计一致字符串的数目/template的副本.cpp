//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(char c: allowed) s.insert(c);
        int res = 0;
        for(auto &word: words) {
            int flag = 1;
            for(int i = 0; i < word.size(); i++) {
                if (!s.count(word[i])) {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
