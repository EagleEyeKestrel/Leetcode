//
//  main.cpp
//  其实就是简单的遍历一下树结构。dfs返回一个子树的节点和
//  Copyright © 2021 ji luyang. All rights reserved.
//

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;
    int getImportance(vector<Employee*> employees, int id) {
      for (auto e: employees) {
          mp[e->id] = e;
      }
      return dfs(id);
    }
    int dfs(int id) {
        int res = mp[id]->importance;
        for (int sub: mp[id]->subordinates) {
            res += dfs(sub);
        }
        return res;
    }
};
