//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minTimeToType(string word) {
        int res = min(abs(word[0] - 'a'),  abs('z' + 1 - word[0]));
        for (int i = 1; i < word.size(); i++) {
            res += min(abs(word[i] - word[i - 1]), 26 - abs(word[i] - word[i - 1]));
        }
        return res + word.size();
    }
};
