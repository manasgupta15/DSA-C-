// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
// Input: stalls[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
// Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
// Output: 1
// Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
// The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
// Constraints:
// 2 <= stalls.size() <= 106
// 0 <= stalls[i] <= 108
// 2 <= k <= stalls.size()



// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k, int minDistance) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int cows = 1, lastPosition = stalls[0];
        
        for(int i = 1; i < n; i++) {
            if((stalls[i] - lastPosition) >= minDistance) {
                cows++;
                lastPosition = stalls[i];
                
                if(cows == k) return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        int ans = -1;
        
        int start = 1;
        int end = *max_element(stalls.begin(), stalls.end());
        
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(isPossible(stalls, k, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
