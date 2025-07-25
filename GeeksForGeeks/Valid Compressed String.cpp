// A special compression mechanism can arbitrarily delete 0 or more characters and replace them with the deleted character count.
// Given two strings, S and T where S is a normal string and T is a compressed string, determine if the compressed string  T is valid for the plaintext string S. 
// Note: If T consists of multiple integers adjacently, consider all of them at a single number. For example T="12B32", consider T as "12" + "B" + "32".  


// Example 1:

// Input:
// S = "GEEKSFORGEEKS"
// T = "G7G3S"
// Output:
// 1
// Explanation:
// We can clearly see that T is a valid 
// compressed string for S.

// Example 2:

// Input:
// S = "DFS"
// T = "D1D"
// Output :
// 0
// Explanation:
// T is not a valid compressed string.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function checkCompressed() which takes 2 strings S and T as input parameters and returns integer 1 if T is a valid compression of S and 0 otherwise.


// Expected Time Complexity: O(|T|)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ |S| ≤ 106
// 1 ≤ |T| ≤ 106
// All characters are either capital or numeric.



// User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int i = 0, j = 0;
        int n = S.length(), m = T.length();

        while (j < m) {
            if (isdigit(T[j])) {
                int count = 0;
                // Read full number (could be multiple digits)
                while (j < m && isdigit(T[j])) {
                    count = count * 10 + (T[j] - '0');
                    j++;
                }
                i += count; // Skip characters in S
            } else {
                // Check character match
                if (i >= n || S[i] != T[j]) return false;
                i++;
                j++;
            }
        }

        return i == n;
    }
};
