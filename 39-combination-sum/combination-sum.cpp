class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = {};
        int sum= 0;
        vector<int> curr= {};
        combinations(nums,target,0,0,curr,ans);
        return ans;   
    }

    void combinations(vector<int> &nums,int target,int sum,int idx,vector<int> &curr,vector<vector<int>> &ans)
    {
        if(target<=sum || idx == nums.size()){
            if(target == sum ) ans.push_back(curr); return;
            return;
        }
        curr.push_back(nums[idx]);
        sum = sum+nums[idx];
        combinations(nums,target,sum ,idx,curr,ans);
        curr.pop_back();
        sum = sum-nums[idx];
        combinations(nums,target ,sum,idx+1,curr,ans);
        
    }
};