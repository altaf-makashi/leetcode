class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num=goal^start;
        int ans=0;
        while(num>0){
            if(num%2==1)ans++;
            num/=2;
        }
        return ans;
    }
};