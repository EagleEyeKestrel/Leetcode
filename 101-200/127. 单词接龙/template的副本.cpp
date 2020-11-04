//
//  main.cpp
//  bfs。由于没给单词和字典的长度，先开始尝试穷举字典，超时，因为有个用例字典长度很大。
//  看到每个单词的长度不会很长，所以才用单词变动一个字母去穷举下一个。
//  另外看到评论区说从endword开始搜索会更快，还没仔细研究
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        if(!dict.count(endWord)) return 0;
        queue<string> q;
        m[beginWord] = 1;
        q.push(beginWord);
        int n = wordList.size();
        while(!q.empty()) {
            string tmp = q.front();
            q.pop();
            for(int i = 0; i < tmp.size(); i++) {
                string newtmp = tmp;
                for(int j = 0; j < 25; j++) {
                    newtmp[i]++;
                    if(newtmp[i] > 'z') newtmp[i] -= 26;
                    if(dict.count(newtmp) && !m.count(newtmp)) {
                        m[newtmp] = m[tmp] + 1;
                        if(newtmp == endWord) return m[newtmp];
                        q.push(newtmp);
                    }
                }
            }
        }
        return 0;
    }
};
