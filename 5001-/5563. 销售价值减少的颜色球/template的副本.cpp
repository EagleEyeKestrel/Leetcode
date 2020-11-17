//
//  main.cpp
//  方法很多，这里是一个自认为比较容易想的方法
//  思路其实很清晰，实现起来有点烧脑
//  贪心，从个数最多的的开始拿，所以排序，之后看拿掉inventory[i]以上所有的球，到哪个i会个数超出orders
//  最后处理尾数。逻辑简单，但是代码实现要注意细节
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int mod = 1e9 + 7;
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        long long now = 0, n = inventory.size(), i = 1, res = 0;
        for( ; i < n; i++) {
            if(now + i * (inventory[i - 1] - inventory[i]) > orders) break;
            now += i * (inventory[i - 1] - inventory[i]);
            res = (res + (i * (inventory[i - 1] + inventory[i] + 1) * (inventory[i - 1] - inventory[i]) / 2)) % mod;
        }
        long long nn = (orders - now) / i;
        res = (res + (2 * inventory[i - 1] - nn + 1) * nn / 2 * i) % mod;
        res = (res + (inventory[i - 1] - nn) * ((orders - now) % i)) % mod;
        return res;
    }
};
