//
//  main.cpp
//  贪心处理，从头开始遍历，如果能变大就变。往后遍历，一直都是，如果一直可以变大就变，直到某一位如果只能变小，就退出
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (change[num[i] - '0'] > num[i] - '0') {
                int j = i;
                while (j < n && change[num[j] - '0'] >= num[j] - '0') {
                    num[j] = change[num[j] - '0'] + '0';
                    j++;
                }
                break;
            }
        }
        return num;
    }
};
