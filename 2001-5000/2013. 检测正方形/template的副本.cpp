//
//  main.cpp
//  n^2的算法，朴素实现，穷举point的对角线
//  但是遇到一个坑，如果用auto it: mp遍历map，不能边遍历边访问mp元素，好像会有问题
//  注意正方形面积不能为0！
//  Copyright © 2021 ji luyang. All rights reserved.
//

class DetectSquares {
public:
    unordered_map<int, int> mp;
    unordered_set<int> points;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        mp[1001 * point[0] + point[1]]++;
        points.insert(1001 * point[0] + point[1]);
    }
    
    int count(vector<int> point) {
        int x0 = point[0], y0 = point[1], res = 0;
        for (int p: points) {
            int x = p / 1001, y = p % 1001, cnt = mp[p];
            if (x == x0 || y == y0) continue;
            int p1 = x * 1001 + y0, p2 = x0 * 1001 + y;
            if (abs(y0 - y) == abs(x0 - x)) {
                res += cnt * mp[p1] * mp[p2];
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
