//
//  main.cpp
//  一个个双指针处理就可以了。我写的有点复杂，讨论了大小写。
//  评论区看到更优雅的双指针，根据query去check pattern，见注释
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool f(string& query, string& pattern) {
        int l = 0, m = query.size(), n = pattern.size(), r = 0;
        while (l < m && r < n) {
            if (isupper(pattern[r])) {
                if (isupper(query[l])) {
                    if (query[l] != pattern[r]) return false;
                    l++, r++;
                } else l++;
            } else {
                if (isupper(query[l])) return false;
                if (query[l] == pattern[r]) l++, r++;
                else l++;
            }
        }
        while (l < m && islower(query[l])) l++;
        return l == m && r == n;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string& query: queries) {
            res.push_back(f(query, pattern));
        }
        return res;
    }
};

/*
 boolean check(String s1 , String s2){
       int index = 0;
       for(int i = 0; i < s1.length(); i ++){
           if(index<s2.length() && s1.charAt(i) == s2.charAt(index)){
               index ++;
           }else if(s1.charAt(i)>='A' && s1.charAt(i)<='Z'){
               return false;
           }
       }
       return index == s2.length();
   }
 */
