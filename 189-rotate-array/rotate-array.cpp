class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    
        int n = nums.size();
        k=k%n;
        for(int i=0;i<n/2;i++){
            int temp = nums[i];
            nums[i] = nums[n-1-i];
            nums[n-1-i]=temp;
        }
        for(int i=0;i<k/2;i++){
            int temp = nums[i];
            nums[i] = nums[k-1-i] ;
            nums[k-1-i] = temp;
        }
        for(int i=k;i<(n+k)/2;i++){
             int  temp = nums[i];
            nums[i]= nums[n+k-1-i];
            nums[n+k-1-i] = temp;

        }
    }
};