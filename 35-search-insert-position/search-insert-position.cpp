class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(target > nums[n-1]){
            return n;
        }

        int l = 0;
        int r = n-1;

        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > target){
                ans = mid;
                r = mid - 1;
            }

            else if(nums[mid] < target){
                l = mid + 1;
            }

            else{
                return mid;
            }
        }

        return ans;
    }
};