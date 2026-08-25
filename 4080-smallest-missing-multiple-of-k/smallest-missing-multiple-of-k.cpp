class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101, false);
        for(int val : nums){
            present[val] = true;
        }

        int j = 1;
        for(int i = 1; i <= 100/k; i++){
            int val = k * i;
            if(!present[val]){
                return val;
            }
            j++;
        }

        return k * j;
    }
};