class Solution {
public:
    void Possiblesets(vector<int> &nums, int n,int idx,vector<int> &arr,vector<vector<int>> &ans){
        if(idx>=n){
             ans.push_back(arr);
             return ;
            }
        
        Possiblesets(nums,n,idx+1,arr,ans);
        arr.push_back(nums[idx]);
        Possiblesets(nums,n,idx+1,arr,ans);
        arr.pop_back();

        }
    
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {};
        vector<int> arr = {};
        Possiblesets(nums,n,0,arr,ans);
        return ans;
        
    }
};