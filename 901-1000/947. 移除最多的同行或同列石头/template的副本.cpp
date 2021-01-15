//
//  main.cpp
//  并查集
//  可以对横坐标或者纵坐标相等的石头连接建图，每一个联通的图都可以化简到只有一个石头
//  所以最后的结果就是 石头的个数-连通图的个数
//  并查集存的是所有的行和列，怎么区分行和列？这里把列加上了1001，来表示列
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[20010], sz[20010];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int x, int y) {
        int px = findp(x), py = findp(y);
        if (sz[px] <= sz[py]) p[px] = py;
        else p[py] = px;
        if (sz[px] == sz[py] && px != py) sz[py]++;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for (int i = 0; i <= 20005 ; i++) p[i] = i, sz[i] = 1;
        for (auto& stone: stones) {
            int x = stone[0], y = stone[1];
            merge(x, y + 10001);
        }
        unordered_set<int> s;
        for (auto& stone: stones) {
            s.insert(findp(stone[0]));
        }
        return n - s.size();
    }
};
