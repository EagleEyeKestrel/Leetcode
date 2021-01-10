//
//  main.cpp
//  比赛时候的解法
//  先处理出所有只含a b的字符串，显然最后的结果是每一个字符串能得到的分数之和
//  对于一个str，先计算cnt：能删除的次数
//  然后讨论x和y的大小关系，比如x>=y，那么就要优先删除"ab"
//  优先删除ab的实现在比赛时开始犯了错
//  这里用的是双指针，看有多少个b是在a之后的。那么尽量删ab，最后删ba
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string& str,int x, int y) {
        int cnta = 0, cntb = 0;
        for (char c: str) {
            if (c == 'a') cnta++;
            else cntb++;
        }
        int cnt = min(cnta, cntb);
        if (x >= y) {
            int cntab = 0, r = 0;
            for (int l = 0; l < str.size(); l++) {
                if (str[l] != 'a') continue;
                while (r <= l || r < str.size() && str[r] != 'b') r++;
                if (r < str.size() && str[r] == 'b') {
                    cntab++;
                    r++;
                } else break;
            }
            return cntab * x + (cnt - cntab) * y;
        }
        int cntba = 0, r = 0;
        for (int l = 0; l < str.size(); l++) {
            if (str[l] != 'b') continue;
            while (r <= l || r < str.size() && str[r] != 'a') r++;
            if (r < str.size() && str[r] == 'a') {
                cntba++;
                r++;
            } else break;
        }
        return cntba * y + (cnt - cntba) * x;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size(), res = 0;
        vector<string> v;
        string tmp = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a' && s[i] != 'b') {
                if (tmp.size()) {
                    v.push_back(tmp);
                    tmp.clear();
                }
            } else {
                tmp.push_back(s[i]);
            }
        }
        if (tmp.size()) v.push_back(tmp);
        for (auto &str: v) {
            res += f(str, x, y);
        }
        
        return res;
    }
};
