// You are given a 0-indexed array nums consisting of positive integers.

// A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.

// Return the total number of good partitions of nums.

// Since the answer may be large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: 8
// Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
// Example 2:

// Input: nums = [1,1,1,1]
// Output: 1
// Explanation: The only possible good partition is: ([1,1,1,1]).
// Example 3:

// Input: nums = [1,2,1,3]
// Output: 2
// Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109


class Solution {
public:
    int MOD = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> last_index;

        for(int i = 0; i < n; i++) {
            last_index[nums[i]] = i;
        }

        int i = 0;
        int j = 0;
        j = max(j, last_index[nums[0]]);
        int result = 1;

        while(i < n) {
            if(i > j) {
                result = (result * 2) % MOD;
            }
            j = max(j, last_index[nums[i]]);
            i++;
        }

        return result;
    }
};
