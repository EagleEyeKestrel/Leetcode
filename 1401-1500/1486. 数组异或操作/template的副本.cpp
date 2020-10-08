//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for(int i = 0; i < n; i++){
            res = res ^ (start + 2 * i);
        }
        return res;
    }
};
