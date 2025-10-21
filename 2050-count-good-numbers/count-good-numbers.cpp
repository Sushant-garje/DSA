class Solution {
public:

    int power(long long base, long long exp){
        int result = 1;
        while(exp>0){
            if(exp%2==1) result = (result*base)%1000000007;

            base = (base * base)%1000000007;
            exp = exp/2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
       long long evenPOs = (n+1)/2;
       long long oddPos = (n)/2;

       long long a = power(5, evenPOs);
       long long b = power(4, oddPos);

       long long mul = (a*b)%1000000007;

       return mul;
        
    }
};