//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string tmp = "";
        int res = -1;
        while(1) {
            if(sequence.find(tmp) != sequence.npos) {
                res++;
                tmp = tmp + word;
            } else break;
        }
        return res;
    }
};
