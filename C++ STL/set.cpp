#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(4);

    for (auto val : s)
    {
        cout << val << " ";
    }

    cout << "\nSize " << s.size() << endl;
    cout << *(s.lower_bound(5)) << endl;
    cout << *(s.upper_bound(3));
}