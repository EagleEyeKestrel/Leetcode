//
//  main.cpp
//  第一次的想法，alpha[i]和num[i]表示前缀和，分别表示前i个元素一共有多少个字母/数字
//  alpha[j]-alpha[i]=num[j]-num[i]
//  等价于alpha[j]-num[j]=alpha[i]-num[i]，哈希存储之前出现过的位置，找到最大长度
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int alpha[n + 1], num[n + 1];
        memset(alpha, 0, sizeof(alpha));
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) {
            if (isalpha(array[i][0])) {
                alpha[i + 1] = alpha[i] + 1;
                num[i + 1] = num[i];
            }
            else if(isalnum(array[i][0])) {
                num[i + 1] = num[i] + 1;
                alpha[i + 1] = alpha[i];
            }
            else {
                num[i + 1] = num[i];
                alpha[i + 1] = alpha[i];
            }
        }
        int maxl = 0, maxpos = -1;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp.count(alpha[i] - num[i])) mp[alpha[i] - num[i]] = i;
            else {
                if (i - mp[alpha[i] - num[i]] > maxl) {
                    maxl = i - mp[alpha[i] - num[i]];
                    maxpos = mp[alpha[i] - num[i]] + 1;
                }
            }
        }
        if (maxpos == -1) return {};
        vector<string> res;
        for (int i = maxpos; i <= maxpos + maxl - 1; i++) res.push_back(array[i - 1]);
        return res;
    }
};
