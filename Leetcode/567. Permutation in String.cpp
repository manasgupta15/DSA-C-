class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         int len1 = s1.length(), len2 = s2.length();
        
        // If s1 is longer, s2 can't contain its permutation
        if (len1 > len2) return false;

        // Frequency arrays for 26 lowercase letters
        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequency for s1 and the first window of s2
        for (int i = 0; i < len1; ++i) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Slide the window across s2
        for (int i = len1; i < len2; ++i) {
            if (freq1 == freq2) return true;

            // Move the window: add new char, remove old one
            freq2[s2[i] - 'a']++;
            freq2[s2[i - len1] - 'a']--;
        }

        // Check the last window
        return freq1 == freq2;
    }
};
