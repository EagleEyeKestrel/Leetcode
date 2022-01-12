//
//  main.cpp
//  比较简单的第三题，直接模拟即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        string res;
        for (int i = 0; i < cols; i++) {
            int x = i, y = 0;
            while (x < cols && y < rows) {
                res.push_back(encodedText[y * cols + x]);
                x++, y++;
            }
        }
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }
};
