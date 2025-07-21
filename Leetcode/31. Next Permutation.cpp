// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size();

        // 1. find the pivot index
        int pivot = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        } 

        // 2. if pivot not found then we will simply return the reverse array(ascending order)
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 3. if pivot found out then we will see from the rightmost element that is nearest greater than pivot element and swap that pivot element with that element
        for(int i = n - 1; i >= pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // 3. Now after that swap element we have to reverse the array to find out the next permutation

        int left = pivot + 1;
        int right = n - 1;

        while(left <= right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
