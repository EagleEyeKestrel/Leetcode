//
//  main.cpp
//  考stl + 图
//  先遍历图，得到不同人的深度
//  然后找到level深度的人，拿到所有的电影，并记录频率
//  最后按要求进行排序
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int g[110][110], depth[110];
        memset(g, 0, sizeof(g));
        int n = watchedVideos.size();
        for (int i = 0; i < n; i++) {
            for (int j: friends[i]) {
                g[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++) depth[i] = -1;
        depth[id] = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int to = 0; to < n; to++) {
                if (depth[to] == -1 && g[tmp][to]) {
                    depth[to] = depth[tmp] + 1;
                    q.push(to);
                }
            }
        }
        vector<int> people;
        for (int i = 0; i < n; i++) {
            if (depth[i] == level) {
                people.push_back(i);
            }
        }
        unordered_set<string> se;
        unordered_map<string, int> freq;
        for (int num: people) {
            for (string video: watchedVideos[num]) {
                se.insert(video);
                freq[video]++;
            }
        }
        vector<string> res(se.begin(), se.end());
        sort(res.begin(), res.end(), [&](auto &a, auto &b) {
            if (freq[a] == freq[b]) return a < b;
            return freq[a] < freq[b];
        });
        return res;
    }
};
