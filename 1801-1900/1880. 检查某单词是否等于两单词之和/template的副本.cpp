//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string s1, s2, s3;
        for (char c: firstWord) s1.push_back(c - 'a' + '0');
        for (char c: secondWord) s2.push_back(c - 'a' + '0');
        for (char c: targetWord) s3.push_back(c - 'a' + '0');
        return stoi(s1) + stoi(s2) == stoi(s3);
    }
};
