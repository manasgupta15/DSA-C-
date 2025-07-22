#include <iostream>
#include <vector>
using namespace std;

int main()
{
    pair<int, int> p = {1, 2};
    cout << "The first element: " << p.first << endl;
    cout << "The second element is: " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << "The first element: " << p2.first << endl;
    cout << "The second element first is: " << p2.second.first << endl;
    cout << "The second element second is: " << p2.second.second << endl;

    vector<pair<int, int>> vec = {{1, 2}, {2, 3}};
    vec.push_back({5,6});
    vec.emplace_back(7,8);

    for (auto p3 : vec)
    {
        cout << p3.first << " " << p3.second << " ";
    }

    return 0;
}