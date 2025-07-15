// Problem: Allocate Minimum Number of Pages
// Source: Popular DSA problem (Binary Search on Answer)

// Problem Statement:
// You are given an array 'arr' of 'n' integers where arr[i] represents the number of pages in the ith book. 
// There are 'k' students and the books need to be distributed among the students such that:
//   1. Each student gets at least one book.
//   2. Each book is allocated to exactly one student.
//   3. Book allocation should be in contiguous order (books cannot be split).
// You have to allocate the books in such a way that the maximum number of pages assigned to a student is minimized.

// Return the minimum number of pages.

// Approach:
// This is a classic Binary Search on Answer problem.
// - The lowest possible number of pages is the max(arr), since a student must be able to read at least the largest book.
// - The highest possible number of pages is the sum(arr), if one student reads all books.
// - Use binary search to find the minimum "maximum" number of pages that can be allocated to 'k' students.
// - In each binary search iteration, check if it is possible to divide the books with the current mid as the max page limit.

// Time Complexity:
// - O(N * log(Sum - Max)) where N is the number of books, Sum is the total pages, and Max is the max number of pages in one book.
// Space Complexity:
// - O(1), no extra space used apart from variables.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<int> &arr, int n, int k, int maxAllowedPages) {
        int students = 1, pages = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxAllowedPages) return false;

            if (pages + arr[i] <= maxAllowedPages) {
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int sum = 0;
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
        }

        int start = maxVal, end = sum, ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(arr, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

// Sample Usage
int main() {
    Solution sol;
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int result = sol.findPages(books, students);
    cout << "Minimum pages: " << result << endl;

    return 0;
}

// File Created: July 15, 2025
