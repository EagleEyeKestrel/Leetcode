//
//  main.cpp
//  基础的问题：判断一个字符串是否是S的子序列，用双指针贪心匹配，对字符串的每个字符，去S中贪心寻找下一个可用字符
//  有这么多的查询，肯定不可能依次去S用双指针匹配，否则复杂度是O(50000*5000*50)
//  显然需要预处理S。预处理一下S中每个字母对应的索引，然后每次贪心的二分查找可用的索引。
//  这样的复杂度就是 50000 + 5000 * 50 * log 50000
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> v[26];
        int n = S.size(), res = 0;
        for (int i = 0; i < n; i++) {
            v[S[i] - 'a'].push_back(i);
        }
        for (string& word: words) {
            int tmp = 0, flag = 1;
            for (char c: word) {
                auto it = lower_bound(v[c - 'a'].begin(), v[c - 'a'].end(), tmp);
                if (it != v[c - 'a'].end()) {
                    tmp = *it + 1;
                } else {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
