// Approach 1
class Solution {
public:
    int t[501][501];
    int solve(int i, int j, vector<int>& piles){
        if(i > j){
            return 0;
        }

        if(i == j){
            return piles[i];
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int take_j = piles[j] + min(solve(i+1, j-1, piles), solve(i, j-2, piles));

        return t[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        int n = piles.size();

        int aliceStones = solve(0, n-1, piles);

        int totalStones = 0;
        for(int i = 0; i < n; i++){
            totalStones += piles[i];
        }
        
        int bobStones = totalStones - aliceStones;

        return aliceStones >= bobStones;
    }
};

// Approach 2
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Notice that,  n is even and the total is odd (Already given in the problem). Split the piles into even-indexed piles (0, 2, 4,.....) and odd-indexed piles (1, 3, 5,....). There are exactly n/2 of each. Since the total is odd, 
        // sum_even ≠ sum_odd, so one group is strictly larger. 
        // Alice simply picks that group which has larger sum.
        // Alice can always pick all odd index elements or all even index elements
        
        return true;
    }
};
