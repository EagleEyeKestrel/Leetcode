//
//  main.cpp
//  很无聊的题，但是却不知道怎么写的很简单
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(char c) {
        if (c == 'R') return 0;
        if (c == 'Y') return 1;
        if (c == 'G') return 2;
        return 3;
    }
    vector<int> masterMind(string solution, string guess) {
        int res1 = 0, res2 = 0;
        int cnt1[4], cnt2[4];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; i < 4; i++) {
            if (solution[i] == guess[i]) res1++;
            else {
                cnt1[f(solution[i])]++;
                cnt2[f(guess[i])]++;
            }
        }
        for (int i = 0; i < 4; i++) {
            res2 += min(cnt1[i], cnt2[i]);
        }
        return {res1, res2};
    }
};
