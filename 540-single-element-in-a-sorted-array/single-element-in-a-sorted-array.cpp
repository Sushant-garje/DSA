class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int en = nums.size()-1;

        while(st<en){
            int mid = st+(en-st)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]) ){
                st = mid+1;
            }
            else{
                en = mid;
            }
        }
        return nums[st];
        
    }
};