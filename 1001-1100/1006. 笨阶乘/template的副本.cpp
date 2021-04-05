//
//  main.cpp
//  分成四个四个一组即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int clumsy(int N) {
        if (N <= 2) return N;
        if (N == 3) return 6;
        int res = N * (N - 1) / (N - 2) + N - 3;
        N -= 4;
        while (N >= 4) {
            res += (-N * (N - 1) / (N - 2) + N - 3);
            N -= 4;
        }
        return res - clumsy(N);
    }
};
