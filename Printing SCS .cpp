int shortestCommonSupersequence(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a DP table to store lengths of shortest common supersequences
    int dp[m + 1][n + 1];

    // Auxiliary table to track the path for reconstruction
    char finalans[m + 1][n + 1];

    // Initialize the top-left corner
    dp[0][0] = 0;

    // Fill the first column: when s2 is empty, supersequence is length of s1
    int o = 1;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = o;
        o++;
    }

    // Fill the first row: when s1 is empty, supersequence is length of s2
    o = 1;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = o;
        o++;
    }

    // Fill the DP table and record decisions in finalans
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match: move diagonally and include character
                dp[i][j] = 1 + dp[i - 1][j - 1];
                finalans[i][j] = 'D'; // Diagonal
            } else {
                // Characters do not match: choose minimum of insert from s1 or s2
                dp[i][j] = min(1 + dp[i][j - 1], 1 + dp[i - 1][j]);
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    finalans[i][j] = 'U'; // Up - from s1
                } else {
                    finalans[i][j] = 'L'; // Left - from s2
                }
            }
        }
    }

    // Reconstruct the shortest common supersequence using finalans table
    int i = m;
    int j = n;
    string ans = "";

    // Traverse back from bottom-right of table
    while (i > 0 && j > 0) {
        if (finalans[i][j] == 'D') {
            ans = s1[i - 1] + ans; // Take common character once
            i--;
            j--;
        } else if (finalans[i][j] == 'U') {
            ans = s1[i - 1] + ans; // Include from s1
            i--;
        } else {
            ans = s2[j - 1] + ans; // Include from s2
            j--;
        }
    }

    // Add remaining characters from s1 (if any)
    while (i > 0) {
        ans = s1[i - 1] + ans;
        i--;
    }

    // Add remaining characters from s2 (if any)
    while (j > 0) {
        ans = s2[j - 1] + ans;
        j--;
    }

    // Print the final shortest common supersequence
    cout << ans << "\n";

    // Return the length of the shortest common supersequence
    return dp[m][n];
}
