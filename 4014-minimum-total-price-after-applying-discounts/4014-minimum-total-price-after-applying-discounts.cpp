class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int n=prices.size();
        int k=discounts.size()-1;
        double sum=0;
        for(int i=n-1;i>=0;i--){
                if(k>=0){
                    double f=prices[i]*discounts[k]/100.0;
                    double p=prices[i]-f;
                    sum+=p;
                    k--;
                    continue;
                }
                sum+=prices[i];
        }
        return sum;
    }
};