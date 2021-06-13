//
//  main.cpp
//  二分答案进行check，比赛的时候用了一个集合去存removable的前k个元素，超时了
//  换成数组就不超时了。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int vis[100010];
    int check(string& s, string& p, int k, vector<int>& v) {
        string news;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < k; i++) vis[v[i]] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (!vis[i]) news.push_back(s[i]);
        }
        int i = 0;
        for (int j = 0; j < p.size(); j++) {
            while (i < news.size() && news[i] != p[j]) i++;
            if (i == news.size()) return 0;
            i++;
        }
        return 1;
        
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int r = removable.size(), l = 0;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(s, p, mid, removable)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
