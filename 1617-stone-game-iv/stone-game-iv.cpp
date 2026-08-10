class Solution {
public:
    // person 1 -> Alice
    // person 0 -> Bob
    int solveForPerson(int person, int n, vector<vector<int>>& dp){
        if(n <= 0){
            return 1 - person;
        }

        if(dp[person][n] != -1){
            return dp[person][n];
        }

        for(int x = 1; x * x <= n; x++){
            int square = x * x;

            if(solveForPerson(1 - person, n - square, dp) == person){
                return dp[person][n] = person;
            }
        }

        return dp[person][n] = 1 - person;
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2, vector<int>(n + 1, -1));
        int result = solveForPerson(1, n, dp);

        return (result == 1) ? true : false;
    }
};