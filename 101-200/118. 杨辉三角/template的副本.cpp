//
//  main.cpp
//  从上一行tmp推下一行newtmp就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows) return {};
        vector<int> tmp = {1};
        vector<vector<int>> res = {{1}};
        for(int i = 2; i <= numRows; i++) {
            vector<int> newtmp = {1};
            for(int j = 1; j < tmp.size(); j++) {
                newtmp.push_back(tmp[j] + tmp[j - 1]);
            }
            newtmp.push_back(1);
            res.push_back(newtmp);
            tmp = newtmp;
        }
        return res;
    }
};
