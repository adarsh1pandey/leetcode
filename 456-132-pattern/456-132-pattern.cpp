class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return false;
        
        vector<int> v(n);
        v[0]=nums[0];
        for(int i=1; i<n; i++)
            v[i]=min(nums[i], v[i-1]);
        
        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top()<=v[i])
                s.pop();
            
            if(!s.empty() && s.top()< nums[i]) return true;
            
            s.push(nums[i]);
        }
        
        return false;
    }
};