//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), cnt = 0;
        for (char c: word) {
            if (isupper(c)) cnt++;
        }
        return cnt == n || cnt == 0 || cnt == 1 && isupper(word[0]);
    }
};
