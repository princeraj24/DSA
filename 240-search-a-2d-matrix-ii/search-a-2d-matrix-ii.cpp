class Solution {
public:
    bool binarySearchCols(int j, vector<vector<int>>& matrix, int target){
        int l = 0;
        int r = matrix.size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[mid][j] > target){
                r = mid - 1;
            }

            else if(matrix[mid][j] < target){
                l = mid + 1;
            }

            else{
                return true;
            }
        }

        return false;
    }

    bool binarySearchRows(int i, vector<vector<int>>& matrix, int target){
        int l = 0;
        int r = matrix[0].size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[i][mid] > target){
                r = mid - 1;
            }

            else if(matrix[i][mid] < target){
                l = mid + 1;
            }

            else{
                return true;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // traversing each rows
        for(int i = 0; i < m; i++){
            if(binarySearchRows(i, matrix, target)){
                return true;
            }
        }

        // traverseing each colums
        for(int j = 0; j < n; j++){
            if(binarySearchCols(j, matrix, target)){
                return true;
            }
        }

        return false;
    }
};