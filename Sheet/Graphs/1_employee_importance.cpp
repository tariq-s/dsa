#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee *> employees, int id)
{
    unordered_map<int, int> map;
    for (int i = 0; i < employees.size(); i++)
        map[employees[i]->id] = i;

    queue<int> Queue;
    Queue.push(id);
    int res = 0;

    while (!Queue.empty())
    {
        int curr = Queue.front();
        ;
        Queue.pop();

        res += employees[map[curr]]->importance;

        for (int subs : employees[map[curr]]->subordinates)
            Queue.push(subs);
    }
    return res;
}