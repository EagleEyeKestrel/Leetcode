//
//  main.cpp
//  倍增法，预处理每个点的2^j次方的祖先，这样每次就能在log时间内进行查询
//  Copyright © 2021 ji luyang. All rights reserved.
//

class TreeAncestor {
public:
    int p[50010][20];
    TreeAncestor(int n, vector<int>& parent) {
        //p[i][j]=p[p[i][j-1]][j-1]
        for (int i = 0; i < n; i++) p[i][0] = parent[i];
        for (int j = 1; 1 << j <= n; j++) {
            for (int i = 0; i < n; i++) {
                int fa = p[i][j - 1];
                if (fa == -1) p[i][j] = -1;
                else p[i][j] = p[fa][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int res = node;
        for (int i = 20; i >= 0; i--) {
            if (k >> i & 1) res = p[res][i];
            if (res == -1) return -1;
        }
        return res;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
