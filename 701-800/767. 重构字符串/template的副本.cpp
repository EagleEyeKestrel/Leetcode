//
//  main.cpp
//  一年前还只能看着别人的思路做，现在能想到更适合自己的思路了
//  显然取决于最大元素。最大元素要间隔排，所以弄个堆
//  奇数情况，极限情况是abacada这样，偶数情况最大个数不能超过一半。
//  判断能不能之后，构造一个字符串。主要是最高频的元素从0开始间隔安排就行了，剩下的也类似处理吧
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, int>> pq;
        int n = S.size();
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(char c: S) {
            cnt[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            pq.push({cnt[i], i});
        }
        if(pq.top().first > n / 2 + n % 2) return "";
        string res;
        res.resize(n);
        int now = 0;
        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            int num = tmp.first;
            while(num--) {
                res[now] = tmp.second + 'a';
                now += 2;
                if(now >= n) now = 1;
            }
        }
        return res;
    }
};
