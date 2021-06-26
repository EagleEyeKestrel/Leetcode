//
//  main.cpp
//  我的做法，只需要一个类，因为两个要去排序的地方，排序的要求都是一样的
//  然后就按部就班实现就好了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class MovieRentingSystem {
public:
    struct Movie {
        int id, shop, price;
        bool operator < (const Movie& nn) const {
            if (price == nn.price && shop == nn.shop) return id < nn.id;
            if (price == nn.price) return shop < nn.shop;
            return price < nn.price;
        }
    };
    set<Movie> has[10010], sold;
    unordered_map<long long, int> mp;
    const long long mod = 1e9 + 7;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e: entries) {
            Movie item;
            item.shop = e[0];
            item.id = e[1];
            item.price = e[2];
            has[item.id].insert(item);
            mp[item.shop * mod + item.id] = item.price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto L = has[movie].begin(), R = has[movie].end();
        while (L != R && res.size() < 5) {
            res.push_back((*L).shop);
            L++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        Movie tmp;
        tmp.shop = shop;
        tmp.id = movie;
        tmp.price = mp[shop * mod + movie];
        sold.insert(tmp);
        has[movie].erase(tmp);
    }
    
    void drop(int shop, int movie) {
        Movie tmp;
        tmp.shop = shop;
        tmp.id = movie;
        tmp.price = mp[shop * mod + movie];
        sold.erase(tmp);
        has[movie].insert(tmp);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        auto L = sold.begin(), R = sold.end();
        while (L != R && res.size() < 5) {
            auto tmp = *L;
            res.push_back({ tmp.shop, tmp.id });
            L++;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
