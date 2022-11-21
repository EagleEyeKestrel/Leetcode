//
//  main.cpp
//  注意边界情况的处理，容易忘记
//  Copyright © 2021 ji luyang. All rights reserved.
//

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char tmp[4];
        int res = 0;
        for (int i = 0; i < n; i += 4) {
            int len = read4(tmp);
            len = min(len, n - i);
            res += len;
            for (int j = 0; j < len; j++)
                *(buf + i + j) = tmp[j];
            if (len < 4)
                break;
        }
        return res;
    }
};