class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map <int , int> mp;
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            int val= target-nums[i];
            if(mp.find(val)!=mp.end()){
               ans.push_back(mp[target-nums[i]]);
               ans.push_back(i);
            }else{
                 mp[nums[i]]=i;
            }
        }
        
        return ans;
    }
};