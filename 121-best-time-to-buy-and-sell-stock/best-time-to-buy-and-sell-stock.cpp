class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;

        int minSoFar = INT_MAX;
        
        for(int i = 0; i < n; i++){
            minSoFar = min(minSoFar, prices[i]);
            maxi = max(maxi, prices[i] - minSoFar);
        }

        return maxi;
    }
};