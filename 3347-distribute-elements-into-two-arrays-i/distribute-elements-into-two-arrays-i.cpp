class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        int lastIdx1 = 0;
        int lastIdx2 = 0;

        vector<int> arr1;
        arr1.push_back(nums[0]);

        vector<int> arr2;
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++){
            if(arr1[lastIdx1] > arr2[lastIdx2]){
                arr1.push_back(nums[i]);
                lastIdx1++;
            }
            else{
                arr2.push_back(nums[i]);
                lastIdx2++;
            }
        }

        vector<int> result;
        for(int val : arr1){
            result.push_back(val);
        }

        for(int val : arr2){
            result.push_back(val);
        }

        return result;
    }
};