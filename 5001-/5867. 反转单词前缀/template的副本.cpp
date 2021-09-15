//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reversePrefix(string word, char ch) {
        if (word.find(ch) == string::npos) return word;
        int pos = word.find(ch);
        reverse(word.begin(), word.begin() + pos + 1);
        return word;
    }
};
