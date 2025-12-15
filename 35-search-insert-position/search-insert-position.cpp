class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st =0;
        int end= nums.size()-1;
        int ans = 0;
        while(end>=st){
            int mid = end-(end-st)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){ end = mid-1; ans = mid;}
            else{st = mid+1; ans = mid+1;}
        }
        return ans;
    }
};