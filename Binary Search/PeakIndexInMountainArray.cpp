// Problem: Peak Index in a Mountain Array
// Source: Leetcode (Binary Search Concept)
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Problem Statement:
// An array arr is a mountain if:
// - arr.length >= 3
// - There exists some index i (0 < i < arr.length - 1) such that:
//   arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array 'arr', return the index 'i' such that arr[i] is the peak of the mountain.

// Approach:
// - The peak of the mountain is the element that is greater than both of its neighbors.
// - We can use binary search to find the peak efficiently.
// - If arr[mid] > arr[mid + 1], then the peak lies on the left (including mid).
// - Otherwise, the peak lies on the right side.

// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1, end = arr.size() - 2;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;
            else if (arr[mid - 1] < arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; // should never be reached for valid mountain arrays
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<int> mountain = {0, 2, 4, 6, 3, 1};
    cout << "Peak index: " << sol.peakIndexInMountainArray(mountain) << endl;
    return 0;
}

// File Created: July 15, 2025
