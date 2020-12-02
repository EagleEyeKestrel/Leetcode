//
//  main.cpp
//  商汤第二题，简单的
//  最基本的贪心，每次都优先放最小的字母
//  但是然后看到大佬们更简洁的代码
//  先初始化为aaa...a，然后从尾巴往前开始写尽可能多的z
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        res.resize(n);
        for(int i = 0; i < n; i++) {
            if(k - 1 <= 26 * (n - 1 - i)) {
                res[i] = 'a';
                k--;
            } else {
                res[i] = k - 26 * (n - 1 - i) + 'a' - 1;
                k = 26 * (n - 1 - i);
            }
        }
        return res;
    }
};
