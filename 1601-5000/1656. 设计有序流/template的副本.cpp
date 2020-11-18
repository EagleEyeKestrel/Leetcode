//
//  main.cpp
//  说的很复杂，但毕竟是简单题，用数组模拟一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class OrderedStream {
public:
    int ptr;
    string a[1024];
    OrderedStream(int n) {
        ptr = 1;
        for(int i = 0; i < n; i++) {
            a[i] = "";
        }
    }
    
    vector<string> insert(int id, string value) {
        a[id] = value;
        vector<string> res;
        while(a[ptr] != "") {
            res.push_back(a[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
