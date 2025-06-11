class Solution {
public:

    // Function to compute the length of the Longest Common Subsequence (LCS)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Ensure the second string is always smaller or equal to the first for space optimization
        if (n > m) {
            return longestCommonSubsequence(text2, text1);
        }

        // Initialize a 2-row DP array for space-optimized LCS
        int dp[2][n + 1];

        // Base case: LCS of any string with empty string is 0
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;
        
        dp[1][0] = 0;

        // Fill DP table row by row
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, extend the LCS by 1
                if (text1[i - 1] == text2[j - 1])
                    dp[1][j] = dp[0][j - 1] + 1;
                else
                    // Otherwise, take the max from excluding either character
                    dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            }

            // Copy current row to previous row for next iteration
            for (int j = 1; j <= n; j++) {
                dp[0][j] = dp[1][j];
            }
        }

        // The final value is the length of the LCS
        return dp[1][n];
    }

    // Function to compute the length of the Shortest Common Supersequence (SCS)
    int shortestCommonSupersequence(string &text1, string &text2) {
        int m = text1.length();
        int n = text2.length();

        // Calculate LCS first
        int subans = longestCommonSubsequence(text1, text2);

        // SCS length = sum of lengths - length of LCS
        return n + m - subans;
    }
};
