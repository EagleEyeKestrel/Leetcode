//
//  main.cpp
//  注意对0的处理。不能直接跳过开头的0，因为数字有可能就是0，比如"0a0"
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int i = 0, n = word.size();
        while (i < n) {
            while (i < n && islower(word[i])) i++;
            if (i == n) break;
            string tmp;
            while (i < n && isdigit(word[i])) {
                tmp.push_back(word[i]);
                i++;
            }
            int start = 0;
            while (start < tmp.size() && tmp[start] == '0') start++;
            s.insert(tmp.substr(start));
        }
        return s.size();
    }
};
