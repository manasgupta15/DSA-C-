// Problem: Single Element in a Sorted Array
// Source: Leetcode (Binary Search Concept)
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

// Problem Statement:
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.

// You must write an algorithm that runs in O(log n) time and O(1) space.

// Approach (Binary Search):
// - In a sorted array with pairs, the first instance of a pair will always be at an even index,
//   and the second one at an odd index, if there were no single element.
// - If this pattern breaks, then the single element lies on the left or right half accordingly.
// - Use binary search to find the element which does not have a matching pair.

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Edge cases
            if (mid == 0 && nums[0] != nums[1]) return nums[mid];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2]) return nums[mid];

            // Main check
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) return nums[mid];

            // Pattern check based on even/odd index
            if (mid % 2 == 0) {
                if (nums[mid - 1] == nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid - 1] == nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1; // should never reach here if input is valid
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    cout << "Single non-duplicate element: " << sol.singleNonDuplicate(nums) << endl;
    return 0;
}

// File Created: July 15, 2025
