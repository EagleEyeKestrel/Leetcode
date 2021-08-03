//
//  main.cpp
//  最烦这种代码实现题了。。有点麻烦
//  server代表一个服务器，task代表一个任务，t是时长，start是开始时间，serverID是所属服务器，w是这个服务器的权重（方便排序）
//  free是空闲服务器的堆，jobs是正在进行的任务堆，先结束的会先pop
//  wait是正在等待执行的任务编号
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct server {
        int id, w;
        bool operator > (const server& s) const {
            if (w == s.w) return id > s.id;
            return w > s.w;
        }
    };
    struct task {
        int t, start, serverID, w;
        bool operator > (const task& task_) const {
            if (t + start == task_.t + task_.start && w == task_.w) return serverID > task_.serverID;
            if (t + start == task_.t + task_.start) return w > task_.w;
            return t + start > task_.t + task_.start;
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size(), n = tasks.size();
        vector<int> res(n);
        priority_queue<server, vector<server>, greater<server>> free;
        priority_queue<task, vector<task>, greater<task>> jobs;
        queue<int> wait;
        for (int i = 0; i < servers.size(); i++) {
            server tmp;
            tmp.id = i;
            tmp.w = servers[i];
            free.push(tmp);
        }

        for (int i = 0; i < tasks.size(); i++) {
            while (!jobs.empty()) {
                auto tp = jobs.top();
                if (tp.t + tp.start <= i) {
                    server news;
                    news.id = tp.serverID;
                    news.w = servers[tp.serverID];
                    free.push(news);
                    jobs.pop();
                } else {
                    break;
                }
            }
            wait.push(i);
            while (!free.empty() && !wait.empty()) {
                int taskID = wait.front();
                int serverID = free.top().id;
                free.pop();
                wait.pop();
                task newtask;
                newtask.serverID = serverID;
                newtask.start = i;
                newtask.t = tasks[taskID];
                newtask.w = servers[serverID];
                jobs.push(newtask);
                res[taskID] = serverID;
            }
        }
        while (!wait.empty()) {
            task finished = jobs.top();
            task newtask;
            newtask.t = tasks[wait.front()];
            newtask.start = finished.t + finished.start;
            newtask.serverID = finished.serverID;
            newtask.w = servers[newtask.serverID];
            jobs.pop();
            res[wait.front()] = finished.serverID;
            jobs.push(newtask);
            wait.pop();
        }
        return res;
    }
};
