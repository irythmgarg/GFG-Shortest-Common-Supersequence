 int shortestCommonSupersequence(string &text1, string &text2) {
     
        int m = text1.length();
        int n = text2.length();

        if (n > m) {
            return shortestCommonSupersequence(text2, text1);
        }

        int dp[2][n + 1];
        int o=0;
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = o;
            o++;
        }
        for (int i = 1; i <= m; i++) {
            dp[1][0]=i;
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[1][j] = dp[0][j - 1] + 1;
                else
                    dp[1][j] = min(dp[0][j], dp[1][j - 1])+1;
            }
            for (int j = 0; j <= n; j++) {
                dp[0][j] = dp[1][j];
            }
        }
        return dp[1][n];
    }
