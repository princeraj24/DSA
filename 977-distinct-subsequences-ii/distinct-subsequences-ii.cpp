class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        int n = s.size();

        vector<long long> dp(n + 1, 0);
        vector<long long> last(26, 0);

        dp[0] = 1;   // empty subsequence

        for(int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1]) % MOD;

            dp[i] = (dp[i] - last[ch] + MOD) % MOD;

            last[ch] = dp[i - 1];
        }

        // remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};