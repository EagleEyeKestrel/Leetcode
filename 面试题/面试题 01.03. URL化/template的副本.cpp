//
//  main.cpp
//  说实话没看懂题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int i = length - 1, j = S.length() - 1;
        while (i >= 0) {
            if (S[i] == ' ') {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } else {
                S[j--] = S[i];
            }
            i--;
        }
        return S.substr(j + 1);
    }
};
