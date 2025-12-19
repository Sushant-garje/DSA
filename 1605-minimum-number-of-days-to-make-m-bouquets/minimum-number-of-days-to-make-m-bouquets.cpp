class Solution {
public:
    int arrmax(vector<int>& arr){
        int max = INT_MIN;
        for(auto val:arr){
            if(val>max) max = val;
        }
        return max;
    }
    int check(vector<int>&bloomDay,int mid,int k){
        int r= 0;
        int ans =0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid/bloomDay[i]){
                r++;
                if(r==k){
                    ans++;
                    r=0;
                }

            }else{
                r=0;
            }

        }

        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > bloomDay.size()/k) return -1;
        int st = *min_element(bloomDay.begin(), bloomDay.end());
        int en = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(st<=en){
            int mid = st+(en-st)/2;
            int bouquet = check(bloomDay,mid,k);
            cout<<mid<<" "<<bouquet<<" ";
            if(bouquet>=m){
                en = mid-1;
                ans = mid;
                cout<<ans<<endl;
            }
            else{
                st = mid+1;
            }
            cout<<endl;
        }
        

        return ans;

        
    }
};