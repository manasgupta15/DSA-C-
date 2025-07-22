#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> &d)
{
    for (int num : d)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> d = {1, 2, 3};
    printDeque(d);
    d.push_back(4);
    d.push_back(5);
    printDeque(d);
    d.push_front(0);
    printDeque(d);
    d.pop_back();
    d.pop_front();
    printDeque(d);

    cout << d.at(2);
    return 0;
}