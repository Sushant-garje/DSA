class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size()-1;
        int row = 0;

        while(col >= 0 && row <= matrix.size()-1){
            if(target == matrix[row][col]){
                return true;
            }
            else if(target > matrix[row][col]){
                row++;
            }
            else{
                col--;
            }

        }

        return false;
        
    }
};