//
//  main.cpp
//  O(n2)的暴力模拟。。看到更好的解法是树状数组
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> p, res;
        for(int i = 1; i <= m; i++) p.push_back(i);
        for(int i = 0; i < n; i++) {
            int index = -1;
            for(int j = 0; j < m; j++) {
                if(p[j] == queries[i]) {
                    res.push_back(j);
                    index = j;
                    break;
                }
            }
            int tmp = p[index];
            for(int j = index; j > 0; j--) {
                p[j] = p[j - 1];
            }
            p[0] = tmp;
        }
        return res;
    }
};
