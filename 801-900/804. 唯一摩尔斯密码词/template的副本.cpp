//
//  main.cpp
//  希望leetcode少出点这种题。 ：）
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string dict[26]={ ".-", "-...", "-.-.", "-..", ".", "..-.", \
        "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", \
        "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", \
        ".--", "-..-", "-.--", "--.." };
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> m;
        int res = 0;
        for (string str: words){
            string tmp;
            for(char c: str) tmp += dict[c - 'a'];
            if (!m.count(tmp)) {
                res++;
                m.insert(tmp);
            }
        }
        return res;
    }
};
