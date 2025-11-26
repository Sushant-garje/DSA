class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int st =0;int en = mat[0].size()-1;
        if(en ==0 &&mat.size()<=1) return {0,0};

        while(st<=en){
            int mid = st+(en-st)/2;
            int max = 0;
            int idx =0;
            for(int i =0;i<mat.size();i++){
                if(max<mat[i][mid]){
                    max = mat[i][mid];
                    idx = i;
                }

            }
            if(mid !=0 && mid!=mat[0].size()-1){
                if(max>mat[idx][mid+1] && max>mat[idx][mid-1]){
                    return {idx,mid};
                    
                }
                else if(max<mat[idx][mid+1]){
                    st =mid+1;


                }
                else{
                    en = mid-1;
                }


            }
            else if(mid ==0){
                if(max>mat[idx][mid+1]){
                    return {idx,mid};
                }
                else{
                    st= mid+1;
                }

            }
            else{
                if(max>mat[idx][mid-1]){
                    return {idx,mid};
                }
                else{
                    en= mid-1;
                }
            }
        }

        return {-1,-1};

        
    }
};