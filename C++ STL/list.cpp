#include <iostream>
#include <list>
using namespace std;

void printList(list<int> &l)
{
    for (int num : l)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(4);
    printList(l);
    l.pop_back();
    l.pop_front();
    printList(l);

    list<int> l2 = {1, 2, 3, 4, 5};
    printList(l2);

    // all are the same as vector
    // in list we can't have the facility of random access element but in vector and deque we have
}