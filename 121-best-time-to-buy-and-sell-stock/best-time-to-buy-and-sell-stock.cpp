class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1){
            return 0;
        }

        vector<int> minPrice(n);
        minPrice[0] = prices[0];
        for(int i = 1; i < n; i++){
            minPrice[i] = min(prices[i], minPrice[i-1]);
        }

        int maxProf = INT_MIN;
        for(int i = 1; i < n; i++){
            int buy = minPrice[i];

            int sell = prices[i];

            maxProf = max(maxProf, sell - buy);
        }

        return maxProf;
    }
};