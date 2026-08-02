class Solution {
public:
    int t[2][50001];
    int n;
    int solveForAlice(int person, int i, vector<int>& stoneValue){
        if(i >= n){
            return 0;
        }

        if(t[person][i] != -1){
            return t[person][i];
        }

        int result = (person == 1) ? INT_MIN : INT_MAX;
        int stones = 0;
        for(int x = i; x <= min(i + 2, n - 1); x++){
            
            stones += stoneValue[x];

            if(person == 1){  // Alice turn
                result = max(result, stones + solveForAlice(0, x + 1, stoneValue));
            }

            else {   //Bob's turn
                result = min(result, solveForAlice(1, x + 1, stoneValue));
            }
        }

        return t[person][i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(t, -1, sizeof(t));

        int total_score = 0;
        for(int i = 0; i < n; i++){
            total_score += stoneValue[i];
        }

        int alice_score = solveForAlice(1, 0, stoneValue);
        int bob_score = total_score - alice_score;

        if(alice_score > bob_score){
            return "Alice";
        }

        else if(bob_score > alice_score){
            return "Bob";
        }

        else{
            return "Tie";
        }
    }
};