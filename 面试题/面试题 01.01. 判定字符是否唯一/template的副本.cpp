//
//  main.cpp
//  题目也没说字符串的内容是不是小写字母，那还是排序最保险
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isUnique(string astr) {
        sort(astr.begin(), astr.end());
        for(int i = 1; i < astr.size(); i++) {
            if(astr[i] == astr[i - 1]) return false;
        }
        return true;
    }
};
