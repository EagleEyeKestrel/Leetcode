//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int now = n - 1;
        while (now >= 0 && s[now] == ' ') now--;
        if (now < 0) return 0;
        int i = now;
        while (i >= 0 && s[i] != ' ') i--;
        return now - i;
    }
};
