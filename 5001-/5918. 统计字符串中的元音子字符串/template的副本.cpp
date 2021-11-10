//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> s;
            for (int j = i; j < n; j++) {
                char c = word[j];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')   s.insert(word[j]);
                else break;
                if (s.size() == 5) res++;
            }
        }
        return res;
    }
};
