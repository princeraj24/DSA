class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool allOdd = true;
        bool allEven = true;

        int minOdd = INT_MAX;
        for(int x : nums1){
            if(x % 2 != 0){
                minOdd = min(minOdd, x);
                allEven = false;
            }

            else{
                allOdd = false;
            }
        }


        if(allEven == true || allOdd == true){
            return true;
        }

        for(int x : nums1){
            // odd
            if(x % 2 != 0){
                continue;
            }
            // even
            else{
                if(minOdd >= x){
                    return false;
                }
            }
        }

        return true;
    }
};