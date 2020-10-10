//
//  main.cpp
//  https://blog.csdn.net/u014156276/article/details/109003862
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int pos[1024];
    int c[2048];
    int size;
    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= size) {
            c[i] += x;
            i += lowbit(i);
        }
    }

    int getsum(int i) {
        int res = 0;
        while(i) {
            res += c[i];
            i -= lowbit(i);
        }
        return res;
    }
    
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        memset(c, 0, sizeof(c));
        size = m + n;
        for(int i = n + 1; i <= n + m; i++) {
            update(i, 1);
            pos[i - n] = i;
        }
        vector<int> res;
        for(int i = 1; i <= n; i++) {
            res.push_back(getsum(pos[queries[i - 1]]) - 1);
            update(pos[queries[i - 1]], -1);
            pos[queries[i - 1]] = n - i + 1;
            update(n - i + 1, 1);
        }
        return res;
    }
};
