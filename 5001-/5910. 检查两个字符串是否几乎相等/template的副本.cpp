//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c: word1) cnt1[c - 'a']++;
        for (char c: word2) cnt2[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (abs(cnt1[i] - cnt2[i]) > 3) return false;
        }
        return true;
    }
};
