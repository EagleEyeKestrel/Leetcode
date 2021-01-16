//
//  main.cpp
//  肯定是py方便，c++可以用stringstream
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int res = 1;
        while (ss >> word) {
            if (word.find(searchWord) == 0) return res;
            res++;
        }
        return -1;
    }
};
