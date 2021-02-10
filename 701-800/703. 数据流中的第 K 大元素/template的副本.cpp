//
//  main.cpp
//  用一个小顶堆保存数据流前k大的元素，就可以实现logn时间的更新了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num: nums) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        while (q.size() > K) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
