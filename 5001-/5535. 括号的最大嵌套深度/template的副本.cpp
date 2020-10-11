//
//  main.cpp
//  数括号就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(), now = 0, res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') now++;
            else if(s[i] == ')') now--;
            res = max(res, now);
        }
        return res;
    }
};
