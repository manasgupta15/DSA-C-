// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

// Return the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered [2,3,4] or only board [1] or nothing but not boards [2,4,5].

// Examples:

// Input: arr[] = [5, 10, 30, 20, 15], k = 3
// Output: 35
// Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20,15], Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35
// Input: arr[] = [10, 20, 30, 40], k = 2
// Output: 60
// Explanation: The most optimal way to paint: Painter 1 allocation : [10,20,30], Painter 2 allocation : [40], Job will be complete at time = 60
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 1000
// Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105
// 1 ≤ k ≤ 105


#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    bool isValid(vector<int> &arr, int n, int k, int maxAllowedTime) {
        int painter = 1;  // Start with first painter
        int time = 0;
        
        for(int i = 0; i < n; i++) {
            if (arr[i] > maxAllowedTime) return false; // One unit exceeds limit

            if(time + arr[i] <= maxAllowedTime) {
                time += arr[i];
            } else {
                painter++;
                time = arr[i];
            }
        }
        
        return painter <= k;
    }

    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;

        for(int num : arr) {
            sum += num;
            maxi = max(maxi, num);
        }

        int start = maxi; // At least one task per painter
        int end = sum;    // At most one painter does all
        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isValid(arr, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};


