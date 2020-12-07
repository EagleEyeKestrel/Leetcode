//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string interpret(string command) {
        string res;
        int n = command.size(), i = 0;
        while(i < n) {
            if(command[i] == 'G') {
                i++;
                res.push_back('G');
            } else if(command[i] == '(') {
                if(command[i + 1] == ')') {
                    res.push_back('o');
                    i += 2;
                } else {
                    res = res + "al";
                    i += 4;
                }
            }
        }
        return res;
    }
};
