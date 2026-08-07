class Solution {
public:
    bool checkDigitProduct(int num, int target){
        int product = 1;
        while(num != 0){
            int digit = num % 10;

            if(digit == 0){
                return true;
            }

            product = product * digit;

            num = num / 10;
        }   

        return (product % target == 0);
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= n + 10; i++){
            if(checkDigitProduct(i, t)){
                return i;
            }
        }

        return 0;
    }
};