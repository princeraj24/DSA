class Solution {
public:
    int n;
    int t[50001];
    int solveDifference(int i, vector<int>& stoneValue){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int stones = 0;
        int result = INT_MIN;
        for(int x = 1; x <= 3; x++){
            if(i + x > n){
                break;
            }

            stones += stoneValue[i + x - 1];
            
            result = max(result, stones - solveDifference(i + x, stoneValue));
        }

        return t[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(t, -1, sizeof(t));
        int netScore = solveDifference(0, stoneValue);

        if(netScore > 0){
            return "Alice";
        }

        if(netScore < 0){
            return "Bob";
        }

        else{
            return "Tie";
        }
    }
};