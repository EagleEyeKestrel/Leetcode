//
//  main.cpp
//  A中的单词要满足 包含每一个B中的单词
//  那么只需要取B中每个单词的最大值即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int m = A.size(), n = B.size();
        int need[26] = { 0 };
        for (int i = 0; i < n; i++) {
            int tmp[26] = { 0 };
            for (char c: B[i]) tmp[c - 'a']++;
            for (int j = 0; j < 26; j++) need[j] = max(need[j], tmp[j]);
        }
        vector<string> res;
        for (string& s: A) {
            int tmp[26] = { 0 };
            for (char c: s) tmp[c - 'a']++;
            int flag = 1;
            for (int j = 0; j < 26; j++) {
                if (tmp[j] < need[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) res.push_back(s);
        }
        return res;
    }
};
