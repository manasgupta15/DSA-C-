// Problem: Search in Rotated Sorted Array
// Source: Leetcode (Binary Search Concept)
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

// Problem Statement:
// There is an integer array nums sorted in ascending order (with distinct values).
// The array is rotated at an unknown pivot index k (0 <= k < nums.length).
// Given the array nums after the rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Approach:
// - Use modified binary search to find the target.
// - One half of the array will always be sorted. Use this to decide where to continue searching.

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return mid;

            if (nums[start] <= nums[mid]) { // Left sorted part
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { // Right sorted part
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "Target found at index: " << sol.search(nums, target) << endl;
    return 0;
}

// File Created: July 15, 2025
