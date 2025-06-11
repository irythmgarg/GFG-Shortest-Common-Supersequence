class Solution {
public:
    // Declare memoization table for DP
    int dp[501][501];

    /**
     * Recursive helper function to compute the length of the shortest
     * common supersequence of s1[i:] and s2[j:] using memoization.
     *
     * @param s1 First string (passed by reference)
     * @param s2 Second string (passed by reference)
     * @param i Current index in s1
     * @param j Current index in s2
     * @return Length of the shortest common supersequence from indices i and j
     */
    int hlo(string &s1, string &s2, int i, int j)
    {
        // If all characters in s1 are used, remaining characters in s2 are added
        if (i >= s1.length()) {
            return s2.length() - j;
        }

        // If all characters in s2 are used, remaining characters in s1 are added
        if (j >= s2.length()) {
            return s1.length() - i;
        }

        // Return memoized result if already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, include it once and move both pointers
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + hlo(s1, s2, i + 1, j + 1);
        }

        // If characters don't match, consider both options:
        // 1. Include s1[i] and move i
        // 2. Include s2[j] and move j
        // Take minimum of both options and add 1
        return dp[i][j] = min(
            1 + hlo(s1, s2, i + 1, j),
            1 + hlo(s1, s2, i, j + 1)
        );
    }

    /**
     * Main function to compute the length of the shortest common supersequence
     * between two strings using top-down DP with memoization.
     *
     * @param s1 First input string
     * @param s2 Second input string
     * @return Length of the shortest common supersequence
     */
    int shortestCommonSupersequence(string &s1, string &s2) {
        // Initialize DP table with -1 (uncomputed states)
        memset(dp, -1, sizeof(dp));

        // Start the recursion from index 0 for both strings
        return hlo(s1, s2, 0, 0);
    }
};
