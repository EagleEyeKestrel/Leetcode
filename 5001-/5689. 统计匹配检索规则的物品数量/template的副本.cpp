//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res = 0, n = items.size();
        for (auto &item: items) {
            if (ruleKey == "type" && ruleValue == item[0]) res++;
            if (ruleKey == "color" && ruleValue == item[1]) res++;
            if (ruleKey == "name" && ruleValue == item[2]) res++;
        }
        return res;
    }
};
