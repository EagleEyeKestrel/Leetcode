//
//  main.cpp
//  分成几个问题。首先我把比较小的情况，即不爆ll的情况特殊处理了
//  然后是算多少个0 。这个很简单，统计2和5的因字数
//  然后算末五位，也不难，把left right内刚刚统计的2 和5的次数不要乘，剩下的直接带模乘法
//  最难的是算前5位。我当时先用字符串模拟，其实就是每次取前12位，（因为前10位试了精度不够，混过去了。字符串常数大会超时，直接用数字乘，可以看注释里的部分
//  但更好的解法，当时没想到，使用log！对于logsum，前5位应该是10的(logsum-logsum取整+4)次方
//  取对数的技巧，很妙
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long minres = 1;
        int flag = 1;
        for (int i = left; i <= right; i++) {
            if (minres > 1e18 / i) {
                flag = 0;
                break;
            }
            minres *= i;
        }
        if (flag) {
            int zeros = 0;
            string str = to_string(minres);
            while (!str.empty() && str.back() == '0') {
                zeros++;
                str.pop_back();
            }
            if (str.size() > 10) {
                return str.substr(0, 5) + "..." + str.substr(str.size() - 5) + "e" + to_string(zeros);
            }
            return str + "e" + to_string(zeros);
        }
        int five = 0, two = 0;
        for (int i = left; i <= right; i++) {
            int val = i;
            while (val % 5 == 0) {
                five++;
                val /= 5;
            }
            while (val % 2 == 0) {
                two++;
                val /= 2;
            }
        }
        int zero = min(two, five);
        long long last = 1;
        int rfive = zero, rtwo = zero;
        for (int i = left; i <= right; i++) {
            int val = i;
            while (rfive > 0 && val % 5 == 0) val /= 5, rfive--;
            while (rtwo > 0 && val % 2 == 0) val /= 2, rtwo--;
            last = last * val % 100000;
        }
        string last5 = to_string(last);
        while (last5.size() < 5) last5.insert(last5.begin(), '0');
        /*long long first5 = 1;
        for (int i = left; i <= right; i++) {
            first5 = first5 * i;
            while (first5 > 1000000000000) first5 /= 10;
        }*/
        double logsum = 0;
        for (int i = left; i <= right; i++) {
            logsum += log10(i);
        }
        int first5 = (int)pow(10, logsum - (int)logsum + 4);
        return to_string(first5).substr(0, 5) + "..." + last5 + "e" + to_string(zero);
    }
};
