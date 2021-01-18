//
//  main.cpp
//  栈的思想，贪心，能弹abc就弹abc，弹不了，这个c永远都弹不出去，return false
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isValid(string s) {
        string str;
        for (char c : s) {
            if (c != 'c') str.push_back(c);
            else {
                int n = str.size();
                if (n > 1 && str[n - 1] == 'b' && str[n - 2] == 'a') {
                    str.pop_back();
                    str.pop_back();
                } else return false;
            }
        }
        return str == "";
    }
};
