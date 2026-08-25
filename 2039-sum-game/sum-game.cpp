class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        if(n % 2 != 0){
            return true;
        }

        int leftCnt = 0;
        double leftKnownSum = 0;

        int rightCnt = 0;
        double rightKnownSum = 0;

        for(int i = 0; i < n/2; i++){
            if(num[i] == '?'){
                leftCnt++;
            }

            if(num[n-1-i] == '?'){
                rightCnt++;
            }

            if(num[i] != '?'){
                leftKnownSum += (num[i] - '0');
            }

            if(num[n-1-i] != '?'){
                rightKnownSum += (num[n-1-i] - '0');
            }
        }

        leftKnownSum += 4.5 * leftCnt;
        rightKnownSum += 4.5 * rightCnt;

        return (leftKnownSum == rightKnownSum) ? false : true;
    }
};