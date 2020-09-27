//
//  main.cpp
//  不用管文件名，就计算depth就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(int i = 0; i < logs.size(); i++) {
            if(logs[i] == "../") {
                if(depth > 0) depth--;
            } else if(logs[i] == "./") {
                continue;
            } else {
                depth++;
            }
        }
        return depth;
    }
};
