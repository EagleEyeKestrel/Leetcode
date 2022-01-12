//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for (auto &word: sentences) {
            stringstream ss(word);
            string tmp;
            int cnt = 0;
            while (ss >> tmp) cnt++;
            res = max(res, cnt);
        }
        return res;
    }
};
