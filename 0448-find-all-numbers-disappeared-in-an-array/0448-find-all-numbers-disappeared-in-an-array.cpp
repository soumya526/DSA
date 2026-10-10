class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        unordered_set<int>m;
        vector<int>ans;
        for(int i=0;i<n;i++){
            m.insert(nums[i]);
        }
        for(int i=1;i<=n;i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};