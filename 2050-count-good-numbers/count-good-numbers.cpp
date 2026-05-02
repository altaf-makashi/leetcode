class Solution {
public:
    int mod=1e9+7; 
    long long fun(long long x,long long n){
        if(n==0)return 1.0;
        long long half=fun(x,n/2);
        if(n%2==0)return (half*half)%mod;
        else return (half*half*x)%mod;
    }
    int countGoodNumbers(long long n) {
        long long even_ind=(n+1)/2;
        long long prime_ind=(n)/2;
        long long five=fun(5,even_ind);
        long long four=fun(4,prime_ind);
        return (five*four)%mod;
    }
};