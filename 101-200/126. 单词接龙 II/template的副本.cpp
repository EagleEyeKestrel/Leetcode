//
//  main.cpp
//  没给数据范围，所以怎么搜是个问题，纠结了挺久
//  大概思路是，做了两遍bfs，第一遍预处理，对单词建图。处理出所有词到beginword最近的距离dist,对相应的一次转换的单词之间连边
//  第二次bfs，队列里存的就是路径了，每次取最后一个单词连着的单词入队列
//  不简洁，但也不难理解
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> id;
        for (int i = 0; i < wordList.size(); i++) id[wordList[i]] = i;
        int n = wordList.size();
        id[beginWord] = n;
        int dist[n + 1];
        dist[n] = 0;
        for (int i = 0; i < n; i++) dist[i] = -1;
        vector<int> g[n + 1];
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            string tmp = q.front() == n ? beginWord : wordList[q.front()];
            q.pop();
            for (int i = 0 ; i < tmp.size(); i++) {
                string tmpp = tmp;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == tmp[i]) continue;
                    tmpp[i] = c;
                    if (dict.count(tmpp) && (dist[id[tmpp]] == -1 || dist[id[tmpp]] == dist[id[tmp]] + 1)) {
                        if (dist[id[tmpp]] == -1) q.push(id[tmpp]);
                        dist[id[tmpp]] = dist[id[tmp]] + 1;
                        g[id[tmp]].push_back(id[tmpp]);
                    }
                }
            }
        }

        if (dist[id[endWord]] == -1) return {};
        vector<vector<string>> res;
        vector<string> path = { beginWord };
        queue<vector<string>> q2;
        q2.push(path);
        while (!q2.empty()) {
            vector<string> tmp = q2.front();
            q2.pop();
            if (tmp.back() == endWord) {
                res.push_back(tmp);
                continue;
            }
            for (int to: g[id[tmp.back()]]) {
                vector<string> newtmp = tmp;
                newtmp.push_back(wordList[to]);
                q2.push(newtmp);
            }
        }
        return res;
    }
};
