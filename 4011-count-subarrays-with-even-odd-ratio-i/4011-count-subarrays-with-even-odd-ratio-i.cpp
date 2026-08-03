class Solution {
public:
    bool helper(vector<int>nums,int a,int b){
        int odd=0;
        int even=0;
    
        return false;
    }
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<int>chk;
        int ans=0;
        int odd,even;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            odd=0,even=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0) even++;
                else odd++;
                if(b*even<=a*odd) ans++;
            }
        }
        return ans;
    }
};