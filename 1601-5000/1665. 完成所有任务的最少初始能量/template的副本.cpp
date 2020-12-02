//
//  main.cpp
//  显然是要贪心，但怎么贪永远是个大问题。
//  零神的题解写的很好，我这里就不赘述了，公式什么的很清晰
//  总结一下，要学会列出公式，然后用局部最优解去探查贪心条件！
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size(), res = 0;
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        for(int i = n - 1; i >= 0; i--) {
            res = max(res + tasks[i][0], tasks[i][1]);
        }
        return res;
    }
};
