//
//  main.cpp
//  既然两步不需要代价，说明奇数位的筹码可以全部放到1，偶数位全部放到0
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for(int pos: position) {
            if(pos % 2) odd++;
            else even++;
        }
        return min(odd, even);
    }
};
