class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid = 0;
        int hg = nums.size()-1;

        while(low<hg && mid<=hg){
            if(nums[mid]==2){
                swap(nums[mid],nums[hg]);
                hg--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else{
                mid++;
            }

        
    }
    }
};