//
//  main.cpp
//  浪费时间。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(char c) {
        if (isupper(c)) c += 'a' - 'A';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string toGoatLatin(string S) {
        stringstream ss(S);
        string tmp, res;
        int i = 1;
        while (ss >> tmp) {
            if (f(tmp[0])) tmp += "ma";
            else tmp = tmp.substr(1) + tmp.substr(0, 1) + "ma";
            for (int k = 0; k < i; k++) tmp.push_back('a');
            if (res.size()) res.push_back(' ');
            res += tmp;
            i++;
        }
        return res;
    }
};
