#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &nums)
{
    int n = nums.size();
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    printVector(nums);

    vector<int> nums2(3, 10);
    printVector(nums2);

    vector<int> nums3;
    nums3.push_back(1);
    nums3.push_back(2);
    nums3.push_back(3);
    nums3.push_back(4);
    printVector(nums3);
    nums3.pop_back();
    nums3.pop_back();
    printVector(nums3);

    vector<int> nums4(nums3);
    printVector(nums4);

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << "Capacity of vector is: " << vec.capacity();
    cout << "\nSize of the vector is: " << vec.size();

    // emplace_back is fast as compared to push_back
    cout << endl;
    vec.emplace_back(6);
    printVector(vec);

    cout << vec.at(2) << endl;
    cout << "The front element in vec is: " << vec.front() << endl;
    cout << "The back element in vec is: " << vec.back() << endl;

    // some other functions
    // erase and insert

    vec.erase(vec.begin() + 2, vec.begin() + 5); // end is not included
    printVector(vec);

    vec.insert(vec.begin() + 3, 7);
    printVector(vec);

    // erase and clear reduce size not capacity

    cout << "The vector is empty? " << vec.empty() << endl;

    // learning concept of iterator
    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    return 0;
}