//
//  main.cpp
//  更好的写法是预处理，先把数字的日志交换到后面去，然后排序前面的字母日志
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string> res2, res;
        vector<int> res1;
        string id[128], content[128];
        for (int i = 0; i < n; i++) {
            int p = logs[i].find(' ');
            id[i] = logs[i].substr(0, p);
            string corpus = logs[i].substr(p + 1);
            if (isdigit(corpus[0])) {
                res2.push_back(logs[i]);
                continue;
            } else {
                content[i] = corpus;
                res1.push_back(i);
            }
        }
        sort(res1.begin(), res1.end(), [content, id](int a, int b) {
            if (content[a] == content[b]) return id[a] < id[b];
            return content[a] < content[b];
        });
        for (int x: res1) res.push_back(logs[x]);
        res.insert(res.end(), res2.begin(), res2.end());
        return res;
    }
};
