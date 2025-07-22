#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    // push the element into stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.emplace(4);
    s.pop(); // remove 4

    cout << "The top of stack is: " << s.top() << endl;
    cout << "The size of the stack is: " << s.size() << endl;

    cout << "Is stack is empty? " << s.empty() << endl;

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}