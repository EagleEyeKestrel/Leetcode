//
//  main.cpp
//  懒得再做一遍了，纯字符串处理，直接贴了当时的代码
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            if (text[i] == ' ') sum++;
        }
        vector<string> words;
        string now = "";
        for (int i = 0; i < n; i++) {
            if (text[i] != ' '){
                now.push_back(text[i]);
            } else{
                if (now != "") words.push_back(now);
                now = "";
            }
        }
        if (now != "") words.push_back(now);
        string res;
        if (words.size() == 1) {
            res = words[0];
            for (int j = 0; j < sum; j++) res.push_back(' ');
            return res;
        }
        for (int i = 0; i < words.size(); i++) {
            res += words[i];
            if (i == words.size() - 1) break;
            for (int j = 0; j < sum / (words.size() - 1); j++) res.push_back(' ');
        }
        if (sum % (words.size() - 1)) {
            for (int j = 0; j < sum % (words.size() - 1); j++) res.push_back(' ');
        }
        return res;
    }
};
