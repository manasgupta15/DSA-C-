#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> mpp;
    mpp["Manas"] = 1;
    mpp["Joe"] = 2;
    mpp["Kishor"] = 3;

    mpp.insert(make_pair("Example", 4));
    mpp.emplace(make_pair("example2", 5));

    for (auto num : mpp)
    {
        cout << num.first << " " << num.second << " ";
    }
    cout << endl;
    cout << "count: " << mpp.count("example2") << endl;
    mpp.erase("example2");
    for (auto num : mpp)
    {
        cout << num.first << " " << num.second << " ";
    }
    cout << endl;

    if (mpp.find("Jo") != mpp.end())
    {
        cout << mpp["Joe"];
    }
    else
    {
        cout << "Not Found";
    }
    return 0;
}