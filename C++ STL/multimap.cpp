#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> mpp;
    mpp.emplace("tv", 100);
    mpp.emplace("tv", 100);
    mpp.emplace("tv", 100);

    mpp.erase(mpp.find("tv"));

    for (auto p : mpp)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}