//
//  main.cpp
//  最后一个0，前面有连续偶数个1，就是true
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = n - 2;
        while(i >= 0 && bits[i] == 1) {
            i--;
        }
        return !((n - 2 - i) % 2);
    }
};
