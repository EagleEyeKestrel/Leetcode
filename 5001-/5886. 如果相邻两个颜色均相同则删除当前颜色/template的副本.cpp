//
//  main.cpp
//  看起来是博弈，实际上就是看A和B的连续个数
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int A = 0, B = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && colors[j + 1] == colors[i]) j++;
            int l = j - i + 1;
            if (l > 2) {
                if (colors[i] == 'A') A += l - 2;
                else B += l - 2;
            }
            i = j;
        }
        return A > B;
    }
};
