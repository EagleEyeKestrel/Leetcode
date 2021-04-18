//
//  main.cpp
//  s1维护最小的k个数，s3维护最大的k个数，s2是中间的
//  先全部放在列表v里，当达到m个数的时候，再放进s里，省的麻烦
//  这里选择先插入新的num，然后调整结构，再删除m个之前的元素，调整结构
//  再优化的话，可以写一个函数delete，使得代码更加精简
//  Copyright © 2021 ji luyang. All rights reserved.
//

class MKAverage {
public:
    multiset<int> s1, s2, s3;
    vector<int> v;
    int M, K, flag = 1;
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    MKAverage(int m, int k) {
        M = m, K = k;
    }
    
    void addElement(int num) {
        v.push_back(num);
        if (flag) {
            if (v.size() == M) {
                flag = 0;
                vector<int> vv = v;
                sort(vv.begin(), vv.end());
                for (int i = 0; i < K; i++) {
                    s1.insert(vv[i]);
                    sum1 += vv[i];
                }
                for (int i = vv.size() - 1; i >= vv.size() - K; i--) {
                    s3.insert(vv[i]);
                    sum3 += vv[i];
                }
                for (int i = K; i < vv.size() - K; i++) {
                    s2.insert(vv[i]);
                    sum2 += vv[i];
                }
            }
            return ;
        }
        int val1 = *(s1.rbegin()), val2 = *(s3.begin());
        if (num >= val1 && num <= val2) {
            s2.insert(num);
            sum2 += num;
        } else if (num < val1) {
            s1.insert(num);
            s1.erase(s1.find(val1));
            sum1 = sum1 + num - val1;
            s2.insert(val1);
            sum2 += val1;
        } else {
            s3.insert(num);
            s3.erase(s3.begin());
            sum3 = sum3 + num - val2;
            s2.insert(val2);
            sum2 += val2;
        }

        int out = v[v.size() - M - 1];
        val1 = *(s1.rbegin()), val2 = *(s3.begin());
        if (out > val1 && out < val2) {
            s2.erase(s2.find(out));
            sum2 -= out;
        } else if (out <= val1) {
            s1.erase(s1.find(out));
            sum1 -= out;
            int tmp = *(s2.begin());
            sum1 += tmp;
            sum2 -= tmp;
            s1.insert(tmp);
            s2.erase(s2.begin());
        } else {
            s3.erase(s3.find(out));
            sum3 -= out;
            int tmp = *(s2.rbegin());
            sum3 += tmp;
            sum2 -= tmp;
            s3.insert(tmp);
            s2.erase(s2.find(tmp));
        }
    }
    
    int calculateMKAverage() {
        if (flag) return -1;
        return sum2 / (M - K - K);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
