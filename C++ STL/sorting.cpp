#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {5, 4, 6, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, arr + n, greater<int>());

    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums = {5, 4, 6, 7, 8, 1};
    int size = nums.size();

    sort(nums.begin(), nums.end());

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}