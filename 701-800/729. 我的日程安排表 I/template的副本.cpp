//
//  main.cpp
//  存的是（end, start)这样的键值对。没想到我和一年前的代码写的一模一样。。
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = m.upper_bound(start);
        if(it == m.end() || it->second >= end) {
            m[end] = start;
            return true;
        }
        return false;
    }
};
