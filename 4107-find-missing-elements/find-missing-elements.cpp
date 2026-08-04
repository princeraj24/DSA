class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int mini = 101;
        int maxi = -1;
        for(int val : nums){
            mini = min(mini, val);
            maxi = max(maxi, val);
        }
        
        vector<bool> present(maxi - mini + 1, false);
        for(int val : nums){
            present[val - mini] = true;
        }

        vector<int> ans;
        for(int x = 1; x < present.size(); x++){
            if(!present[x]){
                ans.push_back(x + mini);
            }
        }

        return ans;
    }
};