//
//  main.cpp
//  很无聊的题，取决于n里面最大的数字
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for(char c: n) {
            res = max(res, c - '0');
        }
        return max(1, res);
    }
};
