//
//  main.cpp
//  数据范围有问题，数组长度并不是100以内
//  但就O(n2)的穷举+朴素判断是否相似就能过了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int p[1024];
    int findp(int x) {
        return p[x] == x ? x : (p[x] = findp(p[x]));
    }
    void merge(int a, int b) {
        p[findp(a)] = findp(b);
    }
    int similar(string& s1, string& s2) {
        int n = s1.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) res++;
        }
        return res == 2 || res == 0;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < n; i++) p[i] = i;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j])) {
                    merge(i, j);
                }
            }
        }
        unordered_set<int> se;
        for (int i = 0; i < n; i++) se.insert(findp(i));
        return se.size();
    }
};
