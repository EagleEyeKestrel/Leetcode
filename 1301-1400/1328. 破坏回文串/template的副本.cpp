//
//  main.cpp
//  无法做到的情况显然只有长度为1
//  然后就从开头开始找，找到第一个不是a的字符，把它改成a
//  我第一次就是这么做的，但是WA了，因为没考虑到aba这种情况。
//  如果是奇数长度的字符串，要忽略中间那个字符。
//  如果所有能改的字符都是a，那么把最后一个字符改成b
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        int i = 0;
        while (i < n && (palindrome[i] == 'a' || n % 2 && i == n / 2)) {
            i++;
        }
        if (i < n) palindrome[i] = 'a';
        else palindrome[n - 1] = 'b';
        return palindrome;
    }
};
