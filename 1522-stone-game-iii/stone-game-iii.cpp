class Solution {
public:
    int t[50001];
    int n;
    int solve(int i, vector<int>& stoneValue){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = INT_MIN;
        int stones = 0;
        
        result = max(result, stoneValue[i] - solve(i+1, stoneValue));

        if(i + 1 < n){
            result = max(result, stoneValue[i] + stoneValue[i+1] - solve(i+2, stoneValue));
        }
        
        if(i + 2 < n){
            result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3, stoneValue));
        }

        return t[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(t, -1, sizeof(t));

        int net_Score = solve(0, stoneValue);

        if(net_Score > 0){
            return "Alice";
        }

        else if(net_Score < 0){
            return "Bob";
        }

        else{
            return "Tie";
        }
    }
};