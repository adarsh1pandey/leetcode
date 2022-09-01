class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int, int>> s;
        int n = arr.size();
        vector<int> ans;

        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                ans.push_back(0);
            }
            else if(s.size() && s.top().first > arr[i])
                ans.push_back(s.top().second - i);
            else if(s.size() && s.top().first <= arr[i]){
                while (s.size() && s.top().first <= arr[i])
                {
                    s.pop();
                }
                if(s.size())
                    ans.push_back(s.top().second -  i);
                else
                    ans.push_back(0);

            }
            s.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};