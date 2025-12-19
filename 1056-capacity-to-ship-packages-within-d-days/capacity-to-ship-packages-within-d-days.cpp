class Solution {
public:
    vector<int> arrinfo(vector<int>&arr){
        int sum =0;
        int max = INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(arr[i]>max) max = arr[i];
        }
        return {max,sum};
    }

    int capacity(vector<int>& weights,int mid){
        int sum =0;
        int day =0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum==mid){
                day++;
                sum =0;
            }
            else if(sum>mid){
                day++;
                sum = weights[i];
            } 
        }
        if(sum) day++;

        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int st =arrinfo(weights)[0];
        int en =arrinfo(weights)[1];
        while(st<=en){
            int mid = st+(en-st)/2;
            cout<<st<<" "<<en<<" "<<" "<<mid<<" "<<capacity(weights,mid)<<endl;
            if(capacity(weights,mid)==days){
                en = mid-1;
            }
            else if(capacity(weights,mid)>days){
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }

        return st;
    }
};