class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;
        int uprow = 0;
        int rcol = matrix[0].size()-1;
        int dnrow =matrix.size()-1;
        int lcol = 0;

        while(uprow<=dnrow && rcol>=lcol){
            for(int i=lcol;i<=rcol;i++){
                ans.push_back(matrix[uprow][i]);
            }


            for(int i=uprow+1;i<=dnrow;i++){
                ans.push_back(matrix[i][rcol]);
            }
            
            if(uprow<dnrow){
                for(int i=rcol-1;i>=lcol;i--){
                ans.push_back(matrix[dnrow][i]);

                }
            }
            
            
            

            if(rcol>lcol){
                for(int i=dnrow-1;i>uprow;i--){
                ans.push_back(matrix[i][lcol]);
            }
            }

            

            uprow++;rcol--;dnrow--;lcol++;
            
        }

        return ans;
    }

};