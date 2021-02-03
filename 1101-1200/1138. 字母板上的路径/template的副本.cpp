//
//  main.cpp
//  本来是很简单的题，但要注意一点，z是凸出来的，所以移动的顺序要讲究
//  从别的地方到z，就要优先向左移。从z到别的地方，那就优先向上移
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int x = 0, y = 0;
        for (char c: target) {
            int tx = (c - 'a') / 5, ty = (c - 'a') % 5;
            while (y > ty) y--, res.push_back('L');
            while (x > tx) x--, res.push_back('U');
            while (x < tx) x++, res.push_back('D');
            while (y < ty) y++, res.push_back('R');
            res.push_back('!');
        }
        return res;
    }
};
