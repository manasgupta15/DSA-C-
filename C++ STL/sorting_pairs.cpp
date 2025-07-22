#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    if (p1.second == p2.second)
    {
        if (p1.first < p2.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    vector<pair<int, int>> nums = {{5, 2}, {1, 2}, {3, 12}, {2, 11}};

    sort(nums.begin(), nums.end(), comparator);

    for (auto p : nums)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}