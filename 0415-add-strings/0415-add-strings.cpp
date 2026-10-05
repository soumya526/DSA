class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size()-1;
        int n2=num2.size()-1;
        string ans="";
        int carry=0;
        while(n1>=0 ||n2>=0 || carry>0){
            int sum=carry;
            if(n1>=0){
                sum+=num1[n1]-'0';
                n1--;
            }
            if(n2>=0){
                sum+=num2[n2]-'0';
                n2--;
            }
            carry=sum/10;
            ans+=to_string(sum%10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};