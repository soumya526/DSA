class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>s,m;
        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()){
                m.insert(nums2[i]);
            }
        }
        ans.assign(m.begin(),m.end());
        return ans;
    }
};