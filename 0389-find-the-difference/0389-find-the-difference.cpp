class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0;
        int sum2=0;
        for(auto &it:s){
            sum1+=it;
        }
        for(auto &it:t){
            sum2+=it;
        }
        int diff=(sum1>sum2)?(sum1-sum2):(sum2-sum1);
        return (char)(sum2-sum1);
    }
};