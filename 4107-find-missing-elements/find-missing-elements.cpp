class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int val : nums){
            mini = min(mini, val);
            maxi = max(maxi, val);
        }
        
        unordered_map<int, int> freq;
        for(int val : nums){
            freq[val]++;
        }

        vector<int> ans;
        for(int x = mini + 1; x < maxi; x++){
            if(freq.find(x) == freq.end()){
                ans.push_back(x);
            }
        }

        return ans;
    }
};