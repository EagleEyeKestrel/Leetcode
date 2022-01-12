//
//  main.cpp
//  我的做法，其实很好理解，关键是对同一时间的要进行同时扩散
//  所以对同一时间的所有人合并成一组，然后把所有已经知道秘密的root存储在set里
//  然后扩散。就是最后要手动把所有的p恢复。 nlogn的，但是常数可能略大。
//  大佬们都用的是图做法，bfs
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[100010];
    int find(int x) {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    void merge(int x, int y) {
        p[find(x)] = p[find(y)];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for (int i = 0; i < n; i++) p[i] = i;
        int vis[n];
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        vis[firstPerson] = 1;
        sort(meetings.begin(), meetings.end(), [&](auto &v1, auto &v2) {
            return v1[2] < v2[2];
        });
        for (int i = 0; i < meetings.size(); i++) {
            int j = i;
            while (j + 1 < meetings.size() && meetings[j + 1][2] == meetings[j][2]) {
                j++;
            }
            for (int k = i; k <= j; k++) {
                merge(meetings[k][0], meetings[k][1]);
            }
            unordered_set<int> roots;
            for (int k = i; k <= j; k++) {
                for (int l = 0; l < 2; l++) {
                    if (vis[meetings[k][l]]) {
                        roots.insert(find(meetings[k][l]));
                    }
                }
            }
            for (int k = i; k <= j; k++) {
                for (int l = 0; l < 2; l++) {
                    if (roots.count(find(meetings[k][l]))) {
                        vis[meetings[k][l]] = 1;
                    }
                }
            }
            for (int k = i; k <= j; k++) {
                for (int l = 0; l < 2; l++) {
                    p[meetings[k][l]] = meetings[k][l];
                }
            }
            i = j;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
