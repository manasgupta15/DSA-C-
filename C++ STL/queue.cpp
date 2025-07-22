#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "front= " << q.front() << endl;
    q.pop();
    cout << "front= " << q.front() << endl;
    cout << "size = " << q.size() << endl;

    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
    return 0;
}