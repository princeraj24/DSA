class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mini = nums[0];
        int maxi = nums[n-1];
        
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