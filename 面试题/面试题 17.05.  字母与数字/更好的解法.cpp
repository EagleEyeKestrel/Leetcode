//
//  main.cpp
//  其实可以把字母看作1，数字看作-1，看前缀和什么时候相等，取最大间隔
//  等价于把解法1里的两个前缀和数组合并了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size(), maxl = 0, maxpos = -1, s = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (isalpha(array[i][0])) s++;
            else if(isalnum(array[i][0])) s--;
            if (mp.count(s)) {
                if (i - mp[s] > maxl) {
                    maxl = i - mp[s];
                    maxpos = mp[s] + 1;
                }
            } else mp[s] = i;
        }
        if (maxpos == -1) return {};
        return vector<string>(array.begin() + maxpos, array.begin() + maxpos + maxl);
    }
};
