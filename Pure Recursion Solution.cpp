class Solution {
public:
    /**
     * Recursive function to find the length of the shortest common supersequence
     * of two strings without using any memoization (pure recursion).
     *
     * @param s1 First string (passed by reference)
     * @param s2 Second string (passed by reference)
     * @param i Current index in s1
     * @param j Current index in s2
     * @return Length of the shortest common supersequence from indices i and j
     */
    int hlo(string &s1, string &s2, int i, int j)
    {
        // Base Case 1: If s1 is fully traversed, return remaining length of s2
        if (i >= s1.length()) {
            return s2.length() - j;
        }

        // Base Case 2: If s2 is fully traversed, return remaining length of s1
        if (j >= s2.length()) {
            return s1.length() - i;
        }

        // If characters match, include it once and move both indices
        if (s1[i] == s2[j]) {
            return 1 + hlo(s1, s2, i + 1, j + 1);
        }

        // If characters don't match:
        // Option 1: Include s1[i] and move i
        // Option 2: Include s2[j] and move j
        // Take the minimum of the two
        int option1 = 1 + hlo(s1, s2, i + 1, j);
        int option2 = 1 + hlo(s1, s2, i, j + 1);

        return min(option1, option2);
    }

    /**
     * Main function that initiates the recursive process to find
     * the shortest common supersequence length.
     *
     * @param s1 First input string
     * @param s2 Second input string
     * @return Length of the shortest common supersequence
     */
    int shortestCommonSupersequence(string s1, string s2) {
        return hlo(s1, s2, 0, 0);  // Start recursion from beginning of both strings
    }
};
