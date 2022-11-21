//
//  main.cpp
//  一方面，需要用数组存之前的read4的剩余部分，所以缓冲数组要放全局
//  只用一个数组就可以解决了，用ptr记录现在的开始位置，sz记录有效部分的大小
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
    char tmp[4];
    int ptr = 0;
    int sz = 0;
    int read(char *buf, int n) {
        int res = 0;
        while (res < n) {
            if (ptr == sz) {
                sz = read4(tmp);
                ptr = 0;
                if (sz == 0)
                    break;
            }
            *(buf + res) = tmp[ptr];
            ptr++, res++;
        }
        *(buf + res) = '\0';
        return res;
    }
};