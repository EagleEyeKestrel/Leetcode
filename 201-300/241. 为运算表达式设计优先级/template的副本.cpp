//
//  main.cpp
//  数据量其实是很小的，常规的区间dp
//  对于区间[i,j]，穷举最后一次计算用到的字符。那么区间[i,j]里可能的结果就是字符两端的子区间里所有可能的和
//  要注意这里是可以重复的，所以用vector
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> num;
        vector<char> op;
        int i = 0;
        while (i < expression.size()) {
            if (isdigit(expression[i])) {
                int j = i;
                while (j + 1 < expression.size() && isdigit(expression[j + 1])) j++;
                num.push_back(stoi(expression.substr(i, j - i + 1)));
                i = j + 1;
            } else {
                op.push_back(expression[i]);
                i++;
            }
        }
        int n = num.size();
        if (n == 1) return { num[0] };
        vector<int> dp[n][n];
        for (int i = 0; i < n; i++) dp[i][i] = { num[i] };
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i; k < j; k++) {
                    char c = op[k];
                    auto v1 = dp[i][k], v2 = dp[k + 1][j];
                    for (int x: v1) {
                        for (int y: v2) {
                            int tmp;
                            if (c == '+') tmp = x + y;
                            if (c == '-') tmp = x - y;
                            if (c == '*') tmp = x * y;
                            dp[i][j].push_back(tmp);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
