//
//  main.cpp
//  比赛的时候没做出来。第二次自己做出来了
//  首先有几个结论，一个是，不难发现对于n=1000...0，是作为特定长度的一串序列的起始，从它变成00..00要2n-1次
//  这里用high表示最高位的1在哪个bit
//  思路是这样的。对于一串100101010...我们需要将其变成11000..然后才能翻转最高位变成01000..，可以直接用上面的结论
//  所以关键是对一串序列如何转化成0100..这里放在f函数处理
//  分两种情况。如果开头两位是11，11xxx我们等价于把xxx部分变成0，递归调用即可
//  如果开头两位是10，10xxx需要把xxx部分变成100..使得原先序列变成101000...，然后翻转第二位变成111000..最后把第三位开始的部分变成000可以直接用结论算出。最后把110000..变成01000
//  关键是怎么把xxx部分变成100... 可以从反向考虑，xxx变成000可以递归求解，然后100...变成000我们是已知的，做差即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int resOfTwoPow(int n) {
        return 2 * n - 1;
    }
    int high(int n) {
        int k = 30;
        while (k >= 0 && ((n >> k) & 1) == 0) k--;
        return k;
    }
    int f(int n) {
        int pos = high(n);
        if ((n >> (pos - 1)) & 1) {
            int tmp = n;
            tmp = tmp ^ (1 << pos);
            tmp = tmp ^ (1 << (pos - 1));
            return minimumOneBitOperations(tmp) + 1;
        }
        int tmp = n;
        tmp = tmp ^ (1 << pos);
        int step1 = (1 << (pos - 1)) - 1 - minimumOneBitOperations(tmp);
        n |= (1 << (pos - 1));
        return step1 + 1 + (1 << (pos - 1)) - 1 + 1;
    }
    int minimumOneBitOperations(int n) {
        if (n <= 1) return n;
        if ((n & (n - 1)) == 0) return resOfTwoPow(n);
        int pos = high(n);
        return f(n) + resOfTwoPow(1 << (pos - 1));
    }
};
