class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 1){
            vector<int> freq(51, 0);
            for(int x : nums){
                freq[x]++;
            }

            int ans = INT_MIN;
            for(int i = 1; i <= 50; i++){
                if(freq[i] == 1){
                    ans = max(ans, i);
                }
            }

            return (ans == INT_MIN) ? -1 : ans;
        }

        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }

        bool firstValid = true;
        bool lastValid = true;

        for(int i = 1; i < n-1; i++){
            if(nums[i] == nums[0]){
                firstValid = false;
            }

            if(nums[i] == nums[n-1]){
                lastValid = false;
            }
        }

        if(nums[0] == nums[n-1]){
            return -1;
        }

        if(lastValid && firstValid){
            return max(nums[0], nums[n-1]);
        }

        else if(lastValid){
            return nums[n-1];
        }

        else if(firstValid){
            return nums[0];
        }

        return -1;
    }
};