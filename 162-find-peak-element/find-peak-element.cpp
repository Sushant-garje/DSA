class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st =0;
        int en = nums.size()-1;

        while(st<en){
            int mid = st+(en-st)/2;
            if(nums[mid]<nums[mid+1]){
                st = mid+1;
            }
            else{
                en =mid;
            }
        }

        return st;
    }
};