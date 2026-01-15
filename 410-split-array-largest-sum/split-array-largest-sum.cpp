class Solution {
public:
    pair<int,int> arrinfo(vector<int> &nums){
        int n = nums.size();
        int max = INT_MIN;
        int sum = 0;
        for(int i= 0;i<n;i++){
            sum +=nums[i];
            if(nums[i]>max) max = nums[i];
        }
        return {max,sum};
    }
    int splits(vector<int> &nums,int mid,int k){
        int split = 1;
        int n = nums.size();
        int lastpos = 0;
        for(int i = 0;i<n;i++){
            if(lastpos+nums[i]<=mid){
                lastpos+=nums[i];
            }
            else{
                split++;
                lastpos =nums[i];
            }
        }

        return split<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        // pair<int,int> p = arrinfo(nums);
        // int sn = p.first;   // max
        // int en = p.second;  // sum
        auto [st, en] = arrinfo(nums);
        while(st<=en){
            int mid = st+(en-st)/2;
            if(splits(nums,mid,k)){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }

        return st;
        
    }
};