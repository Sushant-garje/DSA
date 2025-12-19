class Solution {
public:
    int arrmax(vector<int> &nums){
        int max = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]>max) max = nums[i];
        }
        return max;
    }

    bool divisionsum(vector<int>&nums,int mid,int threshold){
        int sum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%mid ==0){
                sum +=nums[i]/mid;
            }
            else{
                sum +=(nums[i]/mid)+1;
            }

        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) { 
        int st = 1;
        int en = arrmax(nums);
        if(nums.size()==threshold) return en;
        while(st<=en){
            int mid = st+(en-st)/2;
            if(divisionsum(nums,mid,threshold)){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }

        return st;
    }
};