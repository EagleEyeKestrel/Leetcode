//
//  main.cpp
//  垃圾题，没意思
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string maskPII(string S) {
        string res;
        if (S.find('@') != string:: npos) {
            int id = S.find('@');
            res.push_back(tolower(S[0]));
            for (int i = 0; i < 5; i++) res.push_back('*');
            for (int i = id - 1; i < S.size(); i++) res.push_back(tolower(S[i]));
        } else {
            int cnt = 0;
            for (char c: S) if (isdigit(c)) cnt++;
            for (int i = S.size() - 1; i >= 0; i--) {
                if (isdigit(S[i])) {
                    res.push_back(S[i]);
                }
                if (res.size() == 4) break;
            }
            reverse(res.begin(), res.end());
            if (cnt == 10) res = "***-***-" + res;
            else {
                string prev = "+";
                for (int i = 0; i < cnt - 10; i++) prev.push_back('*');
                res = prev + "-***-***-" + res;
            }
        }
        return res;
    }
};
