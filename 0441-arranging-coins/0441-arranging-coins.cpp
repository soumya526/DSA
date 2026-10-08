class Solution {
public:
    int arrangeCoins(int n) {
        long long int st=0,end=n;
        long long int ans=0;
        while(st<=end){
            long long int mid=st+(end-st)/2;
            long long int coinsneeded=mid*(mid+1)/2;
            if(coinsneeded<=n){
                ans=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};