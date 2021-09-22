//
//  main.cpp
//  yysy，第一题非常简单的周赛一般后面都会比较难。。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        res.insert(res.begin(), nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }
};
