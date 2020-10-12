//
//  main.cpp
//  words的长度不多，那直接对于每个word，看其对应的数字即可
//  复杂度是(1000 * 500)，肯定能过了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> res;
        int dict[128];
        for(char c = 'a'; c <= 'o'; c++) {
            dict[c] = (c - 'a') / 3 + 2;
        }
        for(char c = 'p'; c <= 'z'; c++) {
            if(c <= 's') dict[c] = 7;
            else if(c <= 'v') dict[c] = 8;
            else dict[c] = 9;
        }
        for(string& word: words) {
            int flag = 1;
            for(int i = 0; i < word.size(); i++) {
                if(dict[word[i]] != num[i] - '0') {
                    flag = 0;
                    break;
                }
            }
            if(flag) res.push_back(word);
        }
        return res;
    }
};
