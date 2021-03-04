//
//  main.cpp
//  拿到奇数必输，因为奇数-因子(奇数)得到偶数，Bob只需要-1，还给alice又是一个奇数
//  所以bob最后一定可以拿到2 。反之拿偶数必赢，因为最后一定能得到2
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};
