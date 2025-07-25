// You are given an integer array nums.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [1,2,3,4]

// Output: 4

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4].

// Example 2:

// Input: nums = [1,2,1,1,2,1,2]

// Output: 6

// Explanation:

// The longest valid subsequence is [1, 2, 1, 2, 1, 2].

// Example 3:

// Input: nums = [1,3]

// Output: 2

// Explanation:

// The longest valid subsequence is [1, 3].

class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int n = nums.size();

       int countEven = 0; 
       int countOdd = 0;

        for(int &num : nums) {
            if(num % 2 == 0) {
                countEven++;
            } else {
                countOdd++;
            }
        }

          int alternating = 1;
        int parity = nums[0] % 2;

        for(int i = 1; i< n; i++) {
            int currParity = nums[i] % 2;
            if(currParity != parity) {
                alternating++;
                parity = currParity;
            }
        }
        return max({countEven, countOdd, alternating});
    }
};
