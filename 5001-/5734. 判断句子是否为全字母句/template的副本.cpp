//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[128] = { 0 };
        for (char c: sentence) cnt[c]++;
        return !any_of(cnt + 'a', cnt + 'z' + 1, [](int i){
            return i == 0;
        });
    }
};
