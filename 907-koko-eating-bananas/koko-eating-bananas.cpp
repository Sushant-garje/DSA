class Solution {
public:
    int arrmax(vector<int>& arr){
        int max = INT_MIN;
        int n = arr.size();
        for(int i =0;i<n;i++){
            if(arr[i]>max) max = arr[i];
        }
        return max;
    }

    double hours(vector<int>& piles,int mid){
        double h= 0;
        int n = piles.size();
        for(int i= 0;i<n;i++){
           if(piles[i]%mid==0){
            h+=piles[i]/mid;
           }
           else{
            h+=(piles[i]/mid)+1;
           }
        //    cout<<endl<<h<<endl;
        }
        return h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int en = arrmax(piles);
        while(st<=en){
            int mid = st+(en-st)/2;
            double hour = hours(piles,mid);
            // cout<<st<<" "<<en<<" "<<mid<<" "<<hour<<endl;
            if(hour<=h){
                en= mid-1;
            }
            else{
                st= mid+1;
            }
        }
        return st;
    }
};