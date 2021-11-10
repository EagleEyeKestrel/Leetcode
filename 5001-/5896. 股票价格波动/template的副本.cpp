//
//  main.cpp
//  比较简单，stl可以轻易解决，s存储所有正确的价格，mp是时间到价格的映射
//  Copyright © 2021 ji luyang. All rights reserved.
//

class StockPrice {
public:
    multiset<int> s;
    map<int, int> mp;
    StockPrice() {
       
    }
    
    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            int old = mp[timestamp];
            s.erase(s.find(old));
        }
        mp[timestamp] = price;
        s.insert(price);
    }
    
    int current() {
        auto pi = *mp.rbegin();
        return pi.second;
    }
    
    int maximum() {
        return *(s.rbegin());
    }
    
    int minimum() {
        return *(s.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
