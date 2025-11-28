class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == divisor ) return 1;
        bool sign =true;
        if(dividend<0&&divisor>0) sign = false;
        if(divisor<0&&dividend>0) sign = false;
        long n = dividend;
        long m = divisor;
        n = labs(n);
        m = labs(m);
        long ans =0;
        while(n>=m){
            int count = 0;
            while(n >= (m<<(count+1))){
                count++;
            }

            ans = (1<<count)+ans;
            n = n - (m<<count);
        }


        // if((ans>(1<<31)) && sign) return ans;
        // if((ans>=(1<<31)) && !sign) return -ans;

        if(!sign){
            ans = -ans;
        }

        return ans;

        
    }
};