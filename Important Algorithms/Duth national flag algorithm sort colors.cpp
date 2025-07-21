#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force
// void sortColors(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
// }

// optimized approach
// void sortColors(vector<int>& nums) {
//     int n = nums.size();
    
//     int count0 = 0, count1 = 0, count2 = 0;
//     for(int i = 0; i < n; i++) {
//         if(nums[i] == 0) {
//             count0++;
//         } else if(nums[i] == 1) {
//             count1++;
//         } else {
//             count2++;
//         }
//     }
    
//     int index = 0;
//     for(int i = 0; i < count0; i++) {
//         nums[index++] = 0;
//     }
//     for(int i = 0; i < count1; i++) {
//         nums[index++] = 1;
//     }
//     for(int i = 0; i < count2; i++) {
//         nums[index++] = 2;
//     }
// }

// optimal approach - using dutch national flag algorithm
// remember one thing it will take O(n) - single pass
// 0s -> 0 to low - 1
// 1s - low to mid -1
// 2s - high + 1 to n - 1
// unsorted part -> mid to high

void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mid = 0, high = n - 1, low = 0;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }


int main() {
    vector<int>nums = {2,0,2,1,1,0};
    sortColors(nums);
    
    for(int num : nums) {
        cout << num << " ";
    }
    return 0;
}
