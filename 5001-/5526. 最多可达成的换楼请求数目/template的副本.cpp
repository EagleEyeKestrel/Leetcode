//
//  main.cpp
//  。。。蔚来就这？最后一题暴力？好！
//  直接二进制穷举requests取法的种数。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int res = 0, l = requests.size();
        for(int i = 0; i < 1 << l; i++) {
            int cnt[21];
            memset(cnt, 0, sizeof(cnt));
            int nowres = 0;
            for(int j = 0; j < l; j++) {
                if((i >> j) & 1) {
                    cnt[requests[j][0]]--;
                    cnt[requests[j][1]]++;
                    nowres++;
                }
            }
            int flag = 1;
            for(int i = 0; i < n; i++) {
                if(cnt[i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) res = max(res, nowres);
        }
        return res;
    }
};
