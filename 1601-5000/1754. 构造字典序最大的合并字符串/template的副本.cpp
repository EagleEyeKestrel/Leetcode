//
//  main.cpp
//  让我元气大伤的一道题
//  因为这道题一看dp一定能解，然后一看复杂度是n2，我就去dp了
//  本来想用string dp[m][n]来做，然后dp[i][j]=max(word1[i] + dp[i+1][j], word2[j] + dp[i][j+1])
//  发现超内存空间，然后改成滚动数组，因为不知道如何常数时间用word1[i]加入头部，超时
//  然后就发现根本不需要dp，直接贪心就可以了。开始很显然如果word1[i]和word2[j]不等，那么显然取大的
//  但是关键是相等的时候，我们要优先取后面有更大字符的。就行了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        string res;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i == m) {
                res.push_back(word2[j++]);
                continue;
            }
            if (j == n) {
                res.push_back(word1[i++]);
                continue;
            }
            if (word1[i] < word2[j]) {
                res.push_back(word2[j++]);
            } else if (word1[i] > word2[j]) {
                res.push_back(word1[i++]);
            } else {
                int ii = i, jj = j, tmp = -1;
                while (ii < m || jj < n) {
                    if (ii == m) {
                        tmp = 2;break;
                    }
                    if (jj == n) {
                        tmp = 1;break;
                    }
                    if (word1[ii] > word2[jj]) {
                        tmp = 1;
                        break;
                    }
                    if (word1[ii] < word2[jj]) {
                        tmp = 2;
                        break;
                    }
                    ii++, jj++;
                }
                if (tmp == 1) res.push_back(word1[i++]);
                else res.push_back(word2[j++]);
            }
        }
        return res;
    }
};
