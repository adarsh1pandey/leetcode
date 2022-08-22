class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int start = 0;
        int end = numbers.size() - 1;
        
        while (start < end)
        {
            if ((numbers[start] + numbers[end]) > target)
            {
                end--;
            }
            else if (numbers[start] + numbers[end] < target) 
            {
                start++;
            }
            else if (numbers[start] + numbers[end] == target)
            {
                
                
                v.push_back(start + 1);
                v.push_back(end + 1);
                start++;
                end--;
                
            }
        }
        return v;
    }
};