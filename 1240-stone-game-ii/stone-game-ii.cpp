class Solution {
public:
    // person 1 -> Alice
    // person 0 -> Bob
    int t[2][101][101];
    int n;
    int solveForAlice(int person, int i, int M, vector<int>& piles){
        if(i >= n){
            return 0;
        }

        if(t[person][i][M] != -1){
            return t[person][i][M];
        }

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for(int x = 1; x <= min(2 * M, n - i); x++){
            
            stones += piles[i + x - 1];

            if(person == 1){  // Alice turn
                result = max(result, stones + solveForAlice(0, i + x, max(x, M), piles));
            }

            else {   //Bob's turn
                result = min(result, solveForAlice(1, i + x, max(x, M), piles));
            }
        }

        return t[person][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        n = piles.size();

        return solveForAlice(1, 0, 1, piles);
    }
};