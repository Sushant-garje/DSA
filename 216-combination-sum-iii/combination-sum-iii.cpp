class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n) return {};
        vector<vector<int>> ans;
        
        vector<int> curr;
        combinations(k,n,1,ans,curr);
        return ans;
        
    }

    void combinations(int k,int n,int idx,vector<vector<int>> &ans,vector<int> &curr){
        if(idx>10){
            return;
        }
        if(curr.size()>=k){
            if(n==0){
                ans.push_back(curr);
                return;
            }
            return;

        }
        curr.push_back(idx);
        combinations(k,n-idx,idx+1,ans,curr);
        curr.pop_back();
        combinations(k,n,idx+1,ans,curr);

    }
};