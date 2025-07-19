#include<bits/stdc++.h>
using namespace std;

void printAllSubarrays(vector<int>&nums) {
    int n = nums.size();
    
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int k = start; k <= end; k++) {
                cout << nums[k];
            }
            cout <<" ";
        }
        cout << endl;
    }
}

int printMaxSubarraySum(vector<int> &nums) {
    int n = nums.size();
    
    int maxSum = INT_MIN;
    
    for(int start = 0; start < n; start++) {
        int sum = 0;
        for(int end = start; end < n; end++) {
            sum += nums[end];
            maxSum = max(maxSum, sum);
        }
       
    }
    return maxSum;
}

int kadaneAlgorithm(vector<int> &nums) {
    int currSum = 0, maxSum = INT_MIN;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        
        if(currSum < 0) currSum = 0;
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {3,-4,5,4,-1,7,-8};
    printAllSubarrays(nums);
    cout << "THE MAXIMUM SUM IS: " << printMaxSubarraySum(nums);
     cout << "\nTHE MAXIMUM SUM IS: " << kadaneAlgorithm(nums);
}
