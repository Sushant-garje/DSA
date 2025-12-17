class Solution {
public:
    int findMin(vector<int>& nums) {
        int st =0;
        int en = nums.size()-1;
        if(nums[st]<=nums[en]) return nums[st];
        int small=INT_MAX;

        while(st<=en){
            int mid = st+(en-st)/2;
            
           if(nums[st]>nums[en]){
            if(nums[mid]>=nums[st] && nums[mid]>nums[en]){
                st = mid+1;
            }
            else{
                en = mid;
            }

           }
           else{
                return nums[st];
            }
            
        
           
           
        }

        return small;
    }
};