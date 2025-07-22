#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq; // smallest element at the top
    pq.push(3);
    pq.push(1);
    pq.push(5);
    pq.push(0);

    cout << "The top element: " << pq.top() << endl;
}