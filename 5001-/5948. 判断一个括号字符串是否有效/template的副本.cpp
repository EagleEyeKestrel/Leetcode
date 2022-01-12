//
//  main.cpp
//  很简单的题，比赛的时候居然WA了两次
//  首先明确，平衡字符串的条件。所有的l = 所有的r，并且保持l >= r
//  所以对于没有确定的地方，我们要尽可能分配（
//  但要注意，还要考虑到后面已经确定了的(。用rest表示后面还有多少个(，要保证分配(之后不超过n/2
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2) return false;
        string res;
        int n = s.size(), l = 0, r = 0;
        int rest[n];
        rest[n - 1] = (locked.back() == '1' && s.back() == '(');
        for (int i = n - 2; i >= 0; i--) {
            if (locked[i] == '1' && s[i] == '(') rest[i] = rest[i + 1] + 1;
            else rest[i] = rest[i + 1];
        }
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    l++;
                } else {
                    r++;
                }
                
            } else {
                if (l + rest[i] < n / 2) {
                    l++;
                } else {
                    r++;
                }
            }
            if (l < r || l > n / 2 || r > n / 2) return false;
        }
        return true;
    }
};
