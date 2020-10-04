//
//  main.cpp
//  简单题，每次遇到I/X/C 特判一下就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    unordered_map<char, int> dict;
    int romanToInt(string s) {
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        int n = s.size(), res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'I' || s[i] == 'X' || s[i] == 'C') {
                if(i < n - 1 && (dict[s[i + 1]] == dict[s[i]] * 5 || dict[s[i + 1]] == dict[s[i]] * 10)) {
                    res += (dict[s[i + 1]] - dict[s[i]]);
                    i++;
                } else {
                    res += dict[s[i]];
                }
            } else {
                res += dict[s[i]];
            }
        }
        return res;
    }
};
