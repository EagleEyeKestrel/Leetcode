//
//  main.cpp
//  一开始没发现书必须要连着，想了半天。
//  连着的话，用dp[i]表示前i本书，然后直接穷举第i本书和多少连着的书相连即可，最多也就n2
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int j = i, maxh = books[i - 1][1], now_width = books[i - 1][0];
            dp[i] = maxh + dp[i - 1];
            while(j > 1 && now_width + books[j - 2][0] <= shelf_width) {
                j--;
                now_width += books[j - 1][0];
                maxh = max(maxh, books[j - 1][1]);
                dp[i] = min(dp[i], maxh + dp[j - 1]);
            }
        }
        return dp[n];
    }
};
