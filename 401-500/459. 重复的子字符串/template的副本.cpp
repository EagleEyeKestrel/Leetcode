//
//  main.cpp
//  看到重复多次子串构成字符串的题，多去想字符串的拼接
//  比如这里设s=nx，那么s+s=2nx，掐头去尾，中间一定还有
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != string::npos;
    }
};
