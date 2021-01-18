//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size() - 1;
        while (l < r){
            while (l < r && !isalpha(S[l])) l++;
            while (l < r && !isalpha(S[r])) r--;
            swap(S[l++], S[r--]);
        }
        return S;
    }
};
