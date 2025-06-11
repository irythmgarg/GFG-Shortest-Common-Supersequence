/**
 * @brief Computes the length of the Shortest Common Supersequence (SCS) of two strings.
 *
 * The SCS of two strings is the shortest string that has both input strings as subsequences.
 * This implementation uses bottom-up dynamic programming.
 *
 * @param s1 Reference to the first input string
 * @param s2 Reference to the second input string
 * @return Length of the shortest common supersequence
 */
int shortestCommonSupersequence(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();

    // dp[i][j] will hold the length of the SCS of s1[0..i-1] and s2[0..j-1]
    int dp[m + 1][n + 1];

    // Initialize the first cell (both strings empty)
    dp[0][0] = 0;

    // Fill the first column: if s2 is empty, we need to add all characters of s1
    int o = 1;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = o;
        o++;
    }

    // Fill the first row: if s1 is empty, we need to add all characters of s2
    o = 1;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = o;
        o++;
    }

    // Fill the rest of the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match, include it once and move diagonally
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // Else, take the minimum of adding a character from either s1 or s2
            else {
                dp[i][j] = min(1 + dp[i][j - 1], 1 + dp[i - 1][j]);
            }
        }
    }

    // The answer is in the bottom-right cell
    return dp[m][n];
}
