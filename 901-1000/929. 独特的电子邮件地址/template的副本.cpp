//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string &str: emails) {
            string tmp = "";
            int id = str.find('@');
            for (int i = 0; i < id; i++) {
                if (str[i] == '+') break;
                if (str[i] != '.') {
                    tmp.push_back(str[i]);
                }
            }
            tmp += str.substr(id);
            s.insert(tmp);
        }
        return s.size();
    }
};
