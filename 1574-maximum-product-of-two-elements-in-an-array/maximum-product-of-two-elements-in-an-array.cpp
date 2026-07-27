class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi1 = 0;
        int maxi2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > maxi1){
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else if(nums[i] > maxi2){
                maxi2 = nums[i];
            }
        }

        return (maxi2-1)*(maxi1-1);
    }
};