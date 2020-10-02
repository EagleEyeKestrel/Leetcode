//
//  main.cpp
//  纯属送分题
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewellery(J.begin(), J.end());
        int res = 0;
        for(char s: S) {
            if(jewellery.count(s)) res++;
        }
        return res;
    }
};
