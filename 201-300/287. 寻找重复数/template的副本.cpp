//
//  main.cpp
//  经典题，数组的索引与数的关系看作指针
//  重复的数说明有多个数指向同一个数，那就会存在环，于是用快慢指针，比较tricky
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), slow = 0, fast = 0;
        while(1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
