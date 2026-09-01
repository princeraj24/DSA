class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    struct State{
        int r;
        int c;
        int e;
        int collectedLitterMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        int litterBitPos[20][20];  //which bit position does this litter represent
        int litterCount = 0;
        int startRow = 0;
        int startCol = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                litterBitPos[i][j] = -1;

                if(classroom[i][j] == 'S'){
                    startRow = i;
                    startCol = j;
                }

                else if(classroom[i][j] == 'L'){
                    litterBitPos[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1; // 2^litterCount - 1;
        if(litterCount == 0){
            return 0;
        }

        VVVVB visited(m, VVVB(n, VVB(maxEnergy+1, VB(1 << litterCount, false))));

        queue<State> q;
        q.push({startRow, startCol, maxEnergy, 0});
        visited[startRow][startCol][maxEnergy][0] = true;
        
        int moves = 0;
        
        while(!q.empty()){
            int size = q.size();

            while(size--){
                State curr = q.front();
                q.pop();
                if(curr.collectedLitterMask == allCollected){
                    return moves;
                }

                if(curr.e == 0){
                    continue;
                }

                for(auto& dir : directions){
                    int nextRow = curr.r + dir[0];
                    int nextCol = curr.c + dir[1];

                    if(nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n){
                        continue;
                    }

                    char cell = classroom[nextRow][nextCol];
                    if(cell == 'X'){
                        continue;
                    }

                    int nextEnergy = curr.e - 1;
                    int nextMask = curr.collectedLitterMask;
                    
                    if(cell == 'R'){
                        nextEnergy = maxEnergy;
                    }

                    else if(cell == 'L'){
                        int P = litterBitPos[nextRow][nextCol];
                        nextMask |= (1 << P);
                    }

                    if(!visited[nextRow][nextCol][nextEnergy][nextMask]){
                        visited[nextRow][nextCol][nextEnergy][nextMask] = true;
                        q.push({nextRow, nextCol, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }

        return -1;
        // T.C : total states that we will visit = O(m*n*maxEnergy*2^10)
        // S.C : O(m*n*maxEnergy*2^10)
    }
};