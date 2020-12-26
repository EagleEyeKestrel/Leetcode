//
//  main.cpp
//  很明显每次要用常数时间来返回，那就必须要用前缀和。
//  但是我们不能去朴素的存储所有前缀和，否则当分母为0时，我们无法算到结果
//  所以当放进一个0的时候，我们之前所有的 前缀和都可以不用存了。
//  因为当最后k个数，超过这个0的左边了，那一定就是0。所以只需要存0后面的元素乘积
//  Copyright © 2020 ji luyang. All rights reserved.
//

class ProductOfNumbers {
public:
    int res[40010];
    int now = 1;
    ProductOfNumbers() {
        res[0] = 1;
    }
    
    void add(int num) {
        if (num) {
            res[now] = res[now - 1] * num;
            now++;
        } else {
            now = 1;
        }
    }
    
    int getProduct(int k) {
        return k >= now ? 0 : res[now - 1] / res[now - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
