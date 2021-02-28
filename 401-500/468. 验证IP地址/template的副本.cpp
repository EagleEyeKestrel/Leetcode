//
//  main.cpp
//  很无聊的题
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string checkIPv4(string IP, vector<int>& ipv4) {
        for (char c: IP) if (c != '.' && !isdigit(c)) return "Neither";
        ipv4.insert(ipv4.begin(), -1);
        ipv4.push_back(IP.size());
        for (int i = 1; i <= 4; i++) {
            string num = IP.substr(ipv4[i - 1] + 1, ipv4[i] - ipv4[i - 1] - 1);
            if (num.empty() || num.size() > 3 || num != to_string(stoi(num)) || stoi(num) > 255 || num.empty()) return "Neither";
        }
        return "IPv4";
    }
    string checkIPv6(string IP, vector<int>& ipv6) {
        for (char c: IP) if (c == '.') return "Neither";
        ipv6.insert(ipv6.begin(), -1);
        ipv6.push_back(IP.size());
        for (int i = 1; i <= 8; i++) {
            string num = IP.substr(ipv6[i - 1] + 1, ipv6[i] - ipv6[i - 1] - 1);
            if (num.size() > 4 || num.empty()) return "Neither";
            for (char c: num) if (c >= 'g' || c >= 'G' && c <= 'Z') return "Neither";
        }
        return "IPv6";
    }
    string validIPAddress(string IP) {
        vector<int> ipv4, ipv6;
        for (int i = 0; i < IP.size(); i++) {
            if (IP[i] == '.') ipv4.push_back(i);
            if (IP[i] == ':') ipv6.push_back(i);
        }
        if (ipv4.size() == 3 && ipv6.empty()) {
            return checkIPv4(IP, ipv4);
        }
        if (ipv6.size() == 7 && ipv4.empty()) {
            return checkIPv6(IP, ipv6);
        }
        return "Neither";
    }
};
