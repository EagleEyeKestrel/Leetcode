//
//  main.cpp
//  题目说了一大堆，其实不难实现，朴素实现就好了
//  change标记S的一个索引是否需要替换，id建立一个索引和在indexes数组中的索引的映射
//  因为区间不重叠，所以直接遍历不会超时
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = S.size(), m = indexes.size(), now = 0;
        int change[1024] = { 0 }, id[1024];
        string res;
        for (int i = 0; i < m; i++) {
            id[indexes[i]] = i;
            int flag = 1;
            for (int j = 0; j < sources[i].size(); j++) {
                if (S[indexes[i] + j] != sources[i][j]) {
                    flag = 0;
                    break;
                }
            }
            change[indexes[i]] = flag;
        }
        while (now < n) {
            if (!change[now]) res.push_back(S[now++]);
            else {
                int i = id[now];
                for (char c: targets[i]) res.push_back(c);
                now += sources[i].size();
            }
        }
        return res;
    }
};
