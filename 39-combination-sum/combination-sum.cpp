class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = {};
        int sum= 0;
        vector<int> curr= {};
        combinations(nums,target,0,curr,ans);
        return ans;   
    }

    void combinations(vector<int> &nums,int target,int idx,vector<int> &curr,vector<vector<int>> &ans)
    {
        if(target<=0 || idx == nums.size()){
            if(target == 0 ) ans.push_back(curr); return;
            return;
        }
        curr.push_back(nums[idx]);
        combinations(nums,target-nums[idx] ,idx,curr,ans);
        curr.pop_back();
        combinations(nums,target ,idx+1,curr,ans);
        
    }
};