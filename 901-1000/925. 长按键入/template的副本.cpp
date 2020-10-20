//
//  main.cpp
//  并不是很简单的简单题
//  写了个自认为还算简洁的代码。每次统计name和typed中一连串相同的字母
//  一个范围是l到ll，一个范围是r到rr
//  最后满足的条件一定是l==m&&r==n，要注意r==n说明最后不能有多余的其他字符。（WA了一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size(), n = typed.size();
        int l = 0, r = 0;
        while(l < m && r < n) {
            int ll = l, rr = r;
            if(name[l] != typed[r]) return false;
            while(ll < m - 1 && name[ll + 1] == name[ll]) ll++;
            while(rr < n - 1 && typed[rr + 1] == typed[rr]) rr++;
            if(ll - l > rr - r) return false;
            l = ll + 1;
            r = rr + 1;
        }
        return l == m && r == n;
    }
};
