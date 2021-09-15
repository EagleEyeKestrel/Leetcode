//
//  main.cpp
//  看上去非常简单的题，其实要做好不容易
//  一方面，一开始没做出来，因为只用了一个vis数组
//  但实际上，向前跳到i和向后跳到i，是两回事。所以要用两个数组
//  另外，关于为什么上界是6000，可以仔细想想
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct node {
        int pos, step, flag;
    };
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int forbid[6010], visf[6010], visb[6010];
        memset(forbid, 0, sizeof(forbid));
        memset(visf, 0, sizeof(visf));
        memset(visb, 0, sizeof(visb));
        for (int x: forbidden) forbid[x] = 1;
        visf[0] = 1;
        queue<node> q;
        node init;
        init.pos = 0, init.step = 0, init.flag = 0;
        q.push(init);
        while (!q.empty()) {
            node tmp = q.front();
            if (tmp.pos == x) return tmp.step;
            q.pop();
            node newNode;
            newNode.pos = tmp.pos + a;
            newNode.step = tmp.step + 1;
            newNode.flag = 0;
            if (newNode.pos < 6010 && !visf[newNode.pos] && !forbid[newNode.pos]) {
                q.push(newNode);
                visf[newNode.pos] = 1;
            }
            if (tmp.flag == 0) {
                newNode.pos = tmp.pos - b;
                newNode.step = tmp.step + 1;
                newNode.flag = 1;
                if (newNode.pos >= 0 && !visb[newNode.pos] && !forbid[newNode.pos]) {
                    q.push(newNode);
                    visb[newNode.pos] = 1;
                }
            }
        }
        return -1;
    }
};
