//
//  main.cpp
//  第一眼没注意到是把所有的两个字母进行交换，WA了
//  第一个条件说明，每个字符串都可以排序，顺序无关紧要，所以计数表示
//  第二个条件说明。首先字母要一样，因为要现有字符。然后字母一样的话，所有字母的计数排序是一样的
//  因为把所有的两种字母交换，等价于cnt数组里两项交换，也等价于排序
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int cnt1[26], cnt2[26];
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(char c: word1) {
            cnt1[c - 'a']++;
        }
        for(char c: word2) {
            cnt2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] && !cnt2[i] || cnt2[i] && !cnt1[i]) return false;
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};
