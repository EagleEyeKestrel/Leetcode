//
//  main.cpp
//  细心coding题
//  穷举菱形的中心(i,j)，以及菱形的边长，复杂度就是O(mnmin(m,n))
//  所以要在常数时间内得到一个菱形的经过元素和
//  那显然需要前缀和预处理，只不过这里前缀和是斜的
//  用upright[i][j]表示从(i,j)一直往右上的所有元素的和，upleft往左上
//  当然预处理环节可以优化掉一层，这里因为不超时就懒得写了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> res;
        int upright[m][n], upleft[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = 0, r = i, c = j;
                while (0 <= r && r < m && 0 <= c && c < n) {
                    tmp += grid[r][c];
                    r--, c++;
                }
                upright[i][j] = tmp;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = 0, r = i, c = j;
                while (0 <= r && r < m && 0 <= c && c < n) {
                    tmp += grid[r][c];
                    r--, c--;
                }
                upleft[i][j] = tmp;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; i - k >= 0 && i + k < m && j - k >= 0 && j + k < n; k++) {
                    if (!k) {
                        res.insert(grid[i][j]);
                        continue;
                    }
                    int tmp = 0;
                    tmp += upright[i][j - k] - (i >= k + 1 && j + 1 < n ? upright[i - k - 1][j + 1] : 0);
                    tmp += upright[i + k][j] - (i >= 1 && j + k + 1 < n ? upright[i - 1][j + k + 1] : 0);
                    tmp += upleft[i][j + k] - (i >= k + 1 && j >= 1 ? upleft[i - k - 1][j - 1] : 0);
                    tmp += upleft[i + k][j] - (i >= 1 && j >= k + 1 ? upleft[i - 1][j - k - 1] : 0);
                    tmp -= (grid[i][j - k] + grid[i][j + k] + grid[i - k][j] + grid[i + k][j]);
                    res.insert(tmp);
                }
            }
        }
        vector<int> ans;
        for (int k = 0; k < 3; k++) {
            if (res.empty()) break;
            ans.push_back(*(res.rbegin()));
            res.erase(*(res.rbegin()));
        }
        return ans;
    }
};
