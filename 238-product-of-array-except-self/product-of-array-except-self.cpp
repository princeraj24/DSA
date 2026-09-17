class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int cntZero = 0;
        int allProduct = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cntZero++;
            }
            else{
                allProduct = allProduct * nums[i];
            }
        }

        if(cntZero >= 2){
            return ans;
        }

        if(cntZero == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    ans[i] = allProduct;
                    return ans;
                }
            }
        }


        for(int i = 0; i < n; i++){
            ans[i] = allProduct / nums[i];
        }

        return ans;
    }
};