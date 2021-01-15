//
//  main.cpp
//  a b 长度不等时，直接挑长度大的那个就满足
//  如果相等，那任意一个作为答案就可以。所以是max
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
