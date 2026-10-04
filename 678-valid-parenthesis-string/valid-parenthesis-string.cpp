class Solution {
public:
    bool solve(int i, string s, int open, vector<vector<int>>& dp){
        if(open < 0){
            return false;
        }

        if(i == s.size()){
            return open == 0;
        }

        if(dp[i][open] != -1){
            return dp[i][open];
        }

        if(s[i] == '('){
            return dp[i][open] = solve(i+1, s, open+1, dp);
        }

        else if(s[i] == ')'){
            return dp[i][open] = solve(i+1, s, open-1, dp);
        }

        else{
            return dp[i][open] = 
                    solve(i+1, s, open+1, dp) ||
                    solve(i+1, s, open-1, dp) ||
                    solve(i+1, s, open, dp);
        }
    }
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(0, s, 0, dp);
    
    }
};