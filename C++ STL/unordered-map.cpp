#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mpp;

    mpp.emplace("tv", 100);
    mpp.emplace("tv", 100);
    mpp.emplace("laptop", 50);
    mpp.emplace("movie", 70);

    for (auto p : mpp)
    {
        cout << p.first << " " << p.second << endl;
    }
}