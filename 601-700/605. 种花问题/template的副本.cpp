//
//  main.cpp
//  贪心，碰到能种的就种，看最多能种多少个
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size(), res = 0;
        for(int i = 0; i < l; i++) {
            if(!(i > 0 && flowerbed[i - 1] || i < l - 1 && flowerbed[i + 1]) && !flowerbed[i]) {
                flowerbed[i] = 1;
                res++;
            }
        }
        return res >= n;
    }
};
