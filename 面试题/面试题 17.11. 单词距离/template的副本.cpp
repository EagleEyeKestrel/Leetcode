//
//  main.cpp
//  WA了两次。。好菜
//  照理说可以直接在words里去搜两个word的索引
//  这个解法适用于优化情况，去存所有词的出现索引
//  注意双指针的写法，这里根据r去更新l的写法没这个方便
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]].push_back(i);
        }
        vector<int> v1 = mp[word1], v2 = mp[word2];
        int l = 0, r = 0, res = INT_MAX;
        while (l < v1.size() && r < v2.size()) {
            res = min(res, abs(v1[l] - v2[r]));
            if (v1[l] < v2[r]) l++;
            else r++;
        }
        return res;
    }
};
