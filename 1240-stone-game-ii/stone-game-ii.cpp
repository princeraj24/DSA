class Solution {
public:
    int n;
    int t[2][101][101];
    int solveForAlice(int person, int i, int M, vector<int>& piles){
        if(i >= n){
            return 0;
        }

        if(t[person][i][M] != -1){
            return t[person][i][M];
        }

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for(int x = 1; x <= min(2 * M, n - i); x++){ // x bas bata raha hai kitna element le skte hain

            stones += piles[i+x-1];
            
            if(person == 1){
                result = max(result, stones + solveForAlice(0, i + x, max(M, x), piles));
            }

            else{
                result = min(result, solveForAlice(1, i + x, max(M, x), piles));
            }
        }

        return t[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));

        return solveForAlice(1, 0, 1, piles);
    }
};