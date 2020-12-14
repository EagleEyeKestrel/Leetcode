//
//  main.cpp
//  一个比较正常的思路，对字符串排序，m存储排序之后的字符串和res里索引的映射
//  看评论看到一个很骚的思路：用质数表示26个字母，然后只要看每个字符串里数字的乘积。
//  但是这个很容易溢出。但是思路很骚啊
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (!m.count(str)) {
                vector<string> tmp = { strs[i] };
                res.push_back(tmp);
                m[str] = res.size() - 1;
            } else {
                res[m[str]].push_back(strs[i]);
            }
        }
        return res;
    }
};
