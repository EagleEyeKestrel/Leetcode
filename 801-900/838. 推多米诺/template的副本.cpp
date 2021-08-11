//
//  main.cpp
//  记录第一个影响到.的L 和 R的距离，然后比较大小修改.即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int r[n], l[n];
        int now = -1;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') {
                r[i] = (now == -1 ? INT_MAX : i - now);
            }
            if (dominoes[i] == 'R') now = i;
            if (dominoes[i] == 'L') now = -1;
        }
        now = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == '.') {
                l[i] = (now == -1 ? INT_MAX : now - i);
            }
            if (dominoes[i] == 'L') now = i;
            if (dominoes[i] == 'R') now = -1;
        }
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') {
                if (l[i] > r[i]) dominoes[i] = 'R';
                if (l[i] < r[i]) dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};
