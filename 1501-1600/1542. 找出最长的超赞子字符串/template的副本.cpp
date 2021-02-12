//
//  main.cpp
//  也就是求最长的子串，使得子串内，最多只有一个字符只出现了奇数次
//  突破点在于只有数字。考虑穷举右边界i，要获得满足要求的最左的边界
//  用状压表示0-9字符的出现奇偶情况，那么对于右边界i，达到了state
//  之前的状态可以是state，或者是和state有一位不同，相减部分即可达到回文
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size(), res = 0, nowState = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            nowState ^= (1 << (s[i] - '0'));
            if (mp.count(nowState)) {
                res = max(res, i - mp[nowState]);
            } else {
                mp[nowState] = i;
            }
            for (int diff = 0; diff < 10; diff++) {
                int otherState = nowState ^ (1 << diff);
                if (mp.count(otherState)) res = max(res, i - mp[otherState]);
            }
        }
        return res;
    }
};
