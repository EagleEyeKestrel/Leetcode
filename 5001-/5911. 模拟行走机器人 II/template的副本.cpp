//
//  main.cpp
//  大坑题
//  一方面自己实现的时候磕磕绊绊。round要注意-4，然后是逆时针旋转
//  最后最坑的地方，一开始在原点是朝东的，后来到原点就都是朝南了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Robot {
public:
    int m, n, dir;
    int round;
    int x, y;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    Robot(int width, int height) {
        m = width, n = height, dir = 1;
        round = 2 * (m + n) - 4;
        x = 0, y = 0;
    }
    
    void move(int num) {
        if (x == 0 && y == 0) {
            num = num % round ? num % round : round;
        } else {
            num %= round;
        }
        while (num > 0) {
            int dis;
            if (dir == 0) dis = n - 1 - y;
            if (dir == 1) dis = m - 1 - x;
            if (dir == 2) dis = y;
            if (dir == 3) dis = x;
            if (dis == 0) {
                dir = (dir + 3) % 4;
                continue;
            }
            int step = min(dis, num);
            x += dx[dir] * step;
            y += dy[dir] * step;
            num -= step;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "North";
        if (dir == 1) return "East";
        if (dir == 2) return "South";
        return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
