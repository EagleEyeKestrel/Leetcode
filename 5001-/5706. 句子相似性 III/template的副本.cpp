//
//  main.cpp
//  判断一个单词列表能否插入一些单词变成另一个列表的时候
//  可以用双指针，一个指向头部另一个指向尾部，看最后能否达到相邻位置
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(vector<string>& v1, vector<string>& v2) {
        if (v1.size() > v2.size()) return false;
        int l = -1, r = v1.size();
        while (l + 1 < v1.size() && v1[l + 1] == v2[l + 1]) l++;
        while (r - 1 >= 0 && v1[r - 1] == v2[v2.size() - (v1.size() - r) - 1]) r--;
        return r - l <= 1;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        string tmp;
        vector<string> v1, v2;
        while (ss1 >> tmp) v1.push_back(tmp);
        while (ss2 >> tmp) v2.push_back(tmp);
        return f(v1, v2) || f(v2, v1);
    }
};
