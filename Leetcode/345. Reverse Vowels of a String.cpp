// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

// Example 1:

// Input: s = "IceCreAm"

// Output: "AceCreIm"

// Explanation:

// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:

// Input: s = "leetcode"

// Output: "leotcede"

 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.


class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); // make it case-insensitive
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;

        while (start < end) {
            while (start < end && !isVowel(s[start])) start++;
            while (start < end && !isVowel(s[end])) end--;

            // Swap vowels
            swap(s[start], s[end]);
            start++;
            end--;
        }

        return s;
    }
};
