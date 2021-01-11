//
//  main.cpp
//  用c++写的话，用stringstream会方便很多
//  将transaction作为一个输入流ss，然后可以用getline(ss, str, ',')把每一段字符串读入str
//  一年前这道题没做出来。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        int n = transactions.size();
        int t[1024], amount[1024];
        string city[1024], name[1024];
        for (int i = 0; i < n; i++) {
            string transaction = transactions[i];
            stringstream ss(transaction);
            vector<string> tmp;
            string split;
            while (getline(ss, split, ',')) {
                tmp.push_back(split);
            }
            t[i] = stoi(tmp[1]);
            amount[i] = stoi(tmp[2]);
            city[i] = tmp[3];
            name[i] = tmp[0];
        }
        for (int i = 0; i < n; i++) {
            int flag = amount[i] <= 1000;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (!flag) break;
                if (name[i] == name[j] && city[i] != city[j] && abs(t[i] - t[j]) <= 60) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) res.push_back(transactions[i]);
        }
        return res;
    }
};
