//
//  main.cpp
//  其实发现不一样的原因就在于后面有0 。当然要排除0的情况
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
