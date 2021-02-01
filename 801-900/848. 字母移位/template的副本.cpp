//
//  main.cpp
//  前缀和裸题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size();
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;
        }
        for (int i = 0; i < n; i++) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return S;
    }
};
