//
//  main.cpp
//  以前一直以为这道题只有马拉车才能过
//  现在更新了数据范围，是O(n2)的
//  这才发现，以前每次在循环内，我都会更新结果res字符串。
//  现在取而代之，更新的是结果字符串所在的位置以及长度，最后再返回
//  因为如果每次都复制结果字符串给res变量也存在着开销，实际的复杂度变成了O(n3)，要注意
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxpos = 0, maxl = 1;
        int p[n][n];
        for (int i = 0; i < n; i++) p[i][i] = 1;
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i + k <= n; i++) {
                p[i][i + k - 1] = s[i] == s[i + k - 1] && (k > 2 ? p[i + 1][i + k - 2] : 1);
                if (p[i][i + k - 1]) {
                    maxpos = i;
                    maxl = k;
                }
            }
        }
        return s.substr(maxpos, maxl);
    }
};
