//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (i && s[i - 1] == j || i < n - 1 && s[i + 1] == j) {
                        continue;
                    } else {
                        s[i] = j;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
