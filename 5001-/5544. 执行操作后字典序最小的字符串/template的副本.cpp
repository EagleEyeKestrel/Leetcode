//
//  main.cpp
//  直接爆搜了
//  轮转导致的位置变化不超过100种，每一种位置奇数和偶数位置可以有9种变化，所以不会超过万级的字符串个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_set<string> se;
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        string res = s;
        q.push(s);
        se.insert(s);
        while(!q.empty()) {
            string tmp = q.front();
            q.pop();
            string tmp1 = tmp;
            for(int i = 1; i < tmp1.size(); i += 2) {
                tmp1[i] += a;
                if(tmp1[i] > '9') tmp1[i] -= 10;
            }
            if(!se.count(tmp1)) {
                q.push(tmp1);
                if(tmp1 < res) res = tmp1;
                se.insert(tmp1);
            }
            string tmp2 = tmp;
            int n = tmp2.size();
            for(int i = 0; i < n; i++) {
                tmp2[i] = tmp[((i - b) % n + n) % n];
            }
            if(!se.count(tmp2)) {
                q.push(tmp2);
                if(tmp2 < res) res = tmp2;
                se.insert(tmp2);
            }
        }
        return res;
    }
};
