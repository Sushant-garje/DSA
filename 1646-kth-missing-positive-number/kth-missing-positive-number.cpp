class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st = 0;
        int en = arr.size()-1;
        while(st<= en){
            int mid = st+(en-st)/2;
            int missing= arr[mid]-(mid+1);
            if(missing<k){
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }
        // int missing = arr[en]-(en+1);
        
        return en + k+1;
    }
};