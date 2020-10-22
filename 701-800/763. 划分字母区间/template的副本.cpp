//
//  main.cpp
//  不难。不难发现每次如果当前所有字母都已经达到了最后一次出现的地方，那么就可以分割一次
//  所以先记录所有字母最右出现点maxRight
//  vis记录一个字母是否访问过，cnt记录当前有几种字母，match记录当前已经几个字母满足
//  match==cnt时，就可以分割一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int n = S.size(), match = 0, cnt = 0, last = -1;
        int maxRight[26], vis[26];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 26; i++) maxRight[i] = n;
        for(int i = n - 1; i >= 0; i--) {
            if(maxRight[S[i] - 'a'] == n) {
                maxRight[S[i] - 'a'] = i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!vis[S[i] - 'a']) {
                vis[S[i] - 'a'] = 1;
                cnt++;
            }
            if(maxRight[S[i] - 'a'] == i) {
                match++;
            }
            if(match == cnt) {
                res.push_back(i - last);
                last = i;
            }
        }
        return res;
    }
};
