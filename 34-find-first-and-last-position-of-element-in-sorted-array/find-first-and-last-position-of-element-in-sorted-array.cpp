class Solution {
public:
    int firstoccur(vector<int>& nums, int target){
        int st =0;
        int en = nums.size()-1;
        int fo = -1;
        while(st<=en){
            int mid = st+(en-st)/2;
            if(nums[mid] == target){
                fo =mid;
                en = mid-1;
            }
            else if(nums[mid] > target) en = mid-1;
            else{ st = mid+1;}
        }

        return fo;
    }

    int lastoccur(vector<int>& nums, int target){
        int st =0;
        int en = nums.size()-1;
        int lo = -1;
        while(st<=en){
            int mid = st+(en-st)/2;
            if(nums[mid] == target){
                lo =mid;
                st = mid+1;
            }
            else if(nums[mid] > target) en = mid-1;
            else{ st = mid+1;}
        }

        return lo;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        ans[0] = firstoccur(nums,target);
        if(ans[0] == -1) return ans;
        ans[1] = lastoccur(nums,target);
        return ans;


        
    }
};