//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "";
        for(int i = 0; i < S.size(); i++) {
            if(S[i] != '#') s.push_back(S[i]);
            else {
                if(!s.empty()) s.pop_back();
            }
        }
        string t = "";
        for(int i = 0; i < T.size(); i++) {
            if(T[i] != '#') t.push_back(T[i]);
            else {
                if(!t.empty()) t.pop_back();
            }
        }
        return s == t;
    }
};
