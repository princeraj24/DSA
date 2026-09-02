class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool allOdd = true;
        bool allEven = true;
        int lastOdd = -1;

        for(int i =0; i < n; i++){
            // Even check
            if(nums1[i] % 2 == 0){
                allOdd = false;
            }

            // Odd check 
            else{
                allEven = false;
                lastOdd = nums1[i];
            }
        }

        if(allOdd == true || allEven == true){
            return true;
        }

        return true;
    }
};