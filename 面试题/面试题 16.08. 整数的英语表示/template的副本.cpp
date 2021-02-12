//
//  main.cpp
//  好无聊的题。。
//  我的思路，用translate去翻译三位数，然后三位三位的处理
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int a[50] = { 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    string name[50] = { "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty", "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One" };
    string translate(string s, unordered_map<int, string>& mp) {
        if (stoi(s) == 0) return "";
        s = to_string(stoi(s));
        string res;
        if (s.size() == 3) {
            string hundred = s.substr(0, 1);
            res = mp[stoi(hundred)] + " " + "Hundred";
            s = s.substr(1);
        }
        if (stoi(s) == 0) return res;
        if (s.size() == 2) {
            if (!res.empty()) res.push_back(' ');
            if (s[0] == '1' || s[0] == '0') {
                res += mp[stoi(s)];
                return res;
            }
            string s2 = s;
            s2[1] = '0';
            res += mp[stoi(s2)];
            s = s.substr(1);
        }
        if (stoi(s) == 0) return res;
        if (s.size() == 1) {
            if (!res.empty()) res.push_back(' ');
            if (s != "0") res += mp[stoi(s)];
        }
        return res;
    }
    string numberToWords(int num) {
        if (!num) return "Zero";
        string res;
        string str = to_string(num);
        unordered_map<int, string> mp;
        for (int i = 0; i < 27; i++) mp[a[i]] = name[i];
        if (str.size() > 9) {
            res += mp[stoi(str.substr(0, 1))];
            res = res + " " + "Billion";
            str = str.substr(1);
        }
        if (str.size() > 6) {
            string million = translate(str.substr(0, str.size() - 6), mp);
            if (!million.empty()) {
                if (!res.empty()) res.push_back(' ');
                res = res + million + " " + "Million";
            }
            str = str.substr(str.size() - 6);
        }
        if (str.size() > 3) {
            string thousand = translate(str.substr(0, str.size() - 3), mp);
            if (!thousand.empty()) {
                if (!res.empty()) res.push_back(' ');
                res = res + thousand + " " + "Thousand";
            }
            str = str.substr(str.size() - 3);
        }
        if (stoi(str) == 0) return res;
        if (!res.empty()) res.push_back(' ');
        res += translate(str, mp);
        return res;
    }
};
