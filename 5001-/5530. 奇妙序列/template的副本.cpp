//
//  main.cpp
//  之前没遇到过的题，周赛没做出来
//  假设当前插入一个数，之前的乘和加的作用等价于 * mul + add
//  那么可以放入该数对应操作的逆元，也就是( - add) / mul
//  最后用总的 * mul + add，就能得到之后的操作加在这个数上得到的结果。很巧妙
//  其中/mul用费马小定理等价于* mul的p-2次方，写个快速幂
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Fancy {
public:
    long mul, add;
    int mod = 1e9 + 7;
    vector<int> v;
    long qpow(long x, long y) {
        long res = 1, now = x;
        while(y) {
            if(y & 1) res = (res * now) % mod;
            now = (now * now) % mod;
            y >>= 1;
        }
        return res % mod;
    }
    Fancy() {
        mul = 1;
        add = 0;
    }
    
    void append(int val) {
        val = ((val - add) % mod + mod) % mod;
        val =(int)((val * qpow(mul, mod - 2)) % mod);
        v.push_back(val);
    }
    
    void addAll(int inc) {
        add += inc;
    }
    
    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size()) return -1;
        int val = v[idx];
        val = (val * mul) % mod;
        val = (val + add) % mod;
        return val;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
