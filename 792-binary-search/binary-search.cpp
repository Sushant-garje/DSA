class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st =0;
        int end= nums.size()-1;

        while(end>=st){
            int mid = end-(end-st)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }

        return -1;
        
    }
};