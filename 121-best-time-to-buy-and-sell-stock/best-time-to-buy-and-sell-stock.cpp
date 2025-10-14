class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best=prices[0];
        int max = 0;
        
        for(int i=0;i<n;i++){
            if(prices[i]<best){
                best = prices[i];
            }

            int ans = prices[i]-best;
            if(ans>max){
                max= ans;
            }

        }
        return max;
        
    }
};