class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 3){
            return nums[0] * nums[1] * nums[2];
        }

        sort(nums.begin(), nums.end());
        if(nums[0] >= 0){
            return nums[n-1] * nums[n-2] * nums[n-3];
        }

        else{
            if(nums[n-1] > 0){
                int val1 = nums[n-1] * nums[n-2] * nums[n-3];
                int val2 = nums[0] * nums[1] * nums[n-1];

                return max(val1, val2);
            }
            else{
                return nums[n-1] * nums[n-2] * nums[n-3];
            }
        }
    }
};