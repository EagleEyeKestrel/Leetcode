//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string compressString(string S) {
        string res;
        int tmp = 1;
        for (int i = 0; i < S.size(); i++) {
            if (i && S[i] == S[i - 1]) tmp++;
            else tmp = 1;
            if (i == S.size() - 1 || S[i + 1] != S[i]) {
                res.push_back(S[i]);
                res += to_string(tmp);
            }
        }
        return res.size() >= S.size() ? S : res;
    }
};
