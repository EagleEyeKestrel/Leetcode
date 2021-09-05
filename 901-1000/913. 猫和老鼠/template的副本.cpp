//
//  main.cpp
//  涨了个记性，de了好久的bug
//  记忆化搜索是显然的，边界状态也是显然的，关键是平局怎么看？
//  一开始我选择用dp[player][i][j]，player表示是谁的回合，ij是老鼠/猫的位置
//  表示平局的时候，我把正在搜索的dp[player][i][j]标记为0，如果再一次搜到就判平局
//  这显然是不对的，因为我有可能在进入一个状态之后若干层，搜索赢的状态的时候走到这里。但我搜赢得状态可以走其他路来获胜，所以不一定是平局的。
//  然后我就在递归的时候加入一层depth，当depth>=2n的时候 判平局。其实也是不对的，两个状态可能在搜索彼此的必胜策略时出现循环，从而判断深度很大的状态为平局，留下记忆，出现问题
//  所以还是得在dp数组中加一层 depth
//  Copyright © 2021 ji luyang. All rights reserved.
//

int dp[410][210][210];
class Solution {
public:
    int n;
    int f(int depth, int i, int j, vector<vector<int>> &graph) {
        if (depth >= 2 * n) return 0;
        if (i == j) return 2;
        if (i == 0) return 1;
        if (dp[depth][i][j] != -1) return dp[depth][i][j];
        if (depth % 2 == 0) {
            for (int to: graph[i]) {
                if (f(depth + 1, to, j, graph) == 1) {
                    return dp[depth][i][j] = 1;
                }
            }
            for (int to: graph[i]) {
                if (f(depth + 1, to, j, graph) == 0) {
                    return dp[depth][i][j] = 0;
                }
            }
            return dp[depth][i][j] = 2;
        }
        for (int to: graph[j]) {
            if (to == 0) continue;
            if (f(depth + 1, i, to, graph) == 2) {
                return dp[depth][i][j] = 2;
            }
        }
        for (int to: graph[j]) {
            if (to == 0) continue;
            if (f(depth + 1, i, to, graph) == 0) {
                return dp[depth][i][j] = 0;
            }
        }
        return dp[depth][i][j] = 1;
    }
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 1, 2, graph);
    }
};
