//
//  main.cpp
//  老实说蔚来这风格我不是很喜欢，每道题就像阅读理解。
//  其实继承顺序就是个先序遍历，建个树就可以了。
//  ！！但并不用真的建树，直接用map映射一下就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class ThroneInheritance {
public:
    unordered_set<string> died;
    unordered_map<string, vector<string>> m;
    ThroneInheritance(string kingName) {
        m["king"] = {};
    }
    
    void birth(string parentName, string childName) {
        m[parentName].push_back(childName);
        m[childName] = {};
    }
    
    void death(string name) {
        died.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs("king", res);
        return res;
    }

    void dfs(string name, vector<string> &res) {
        if(!died.count(name)) res.push_back(name);
        if(m[name].size()) {
            for(string &child: m[name]) {
                dfs(child, res);
            }
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
