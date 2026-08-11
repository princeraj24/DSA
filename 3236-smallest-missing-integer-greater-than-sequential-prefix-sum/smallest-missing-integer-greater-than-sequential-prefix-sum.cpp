class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0] + 1;
        }

        int prefix_sum = nums[0];
        
        int i = 1;
        while(i < n && nums[i] == nums[i-1] + 1){
            prefix_sum += nums[i];
            i++;
        }

        if(i == n){
            return prefix_sum;
        }

        unordered_map<int, int> mp;
        for(int idx = 0; idx < n; idx++){
            mp[nums[idx]]++;
        }

        while(mp.find(prefix_sum) != mp.end()){
            prefix_sum++;
        }

        return prefix_sum;
    }
};