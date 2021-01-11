//
//  main.cpp
//  基本同126 单词接龙II
//  不难想，但是代码量大，考验debug能力，直接套用代码，懒得再写一遍了。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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
        vector<string> path = { beginWord };
        queue<vector<string>> q2;
        q2.push(path);
        while (!q2.empty()) {
            vector<string> tmp = q2.front();
            q2.pop();
            if (tmp.back() == endWord) {
                return tmp;
            }
            for (int to: g[id[tmp.back()]]) {
                vector<string> newtmp = tmp;
                newtmp.push_back(wordList[to]);
                q2.push(newtmp);
            }
        }
        return {};
    }
};
