//
//  main.cpp
//  很简单的数据结构设计，数组就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Bank {
public:
    vector<long long> v;
    int n;
    Bank(vector<long long>& balance) {
        v = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n) return false;
        account1--, account2--;
        if (v[account1] < money) return false;
        v[account1] -= money;
        v[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > n) return false;
        v[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n) return false;
        account--;
        if (v[account] < money) return false;
        v[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
