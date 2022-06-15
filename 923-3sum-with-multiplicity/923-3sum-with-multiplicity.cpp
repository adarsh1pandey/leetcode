class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
       std::sort(arr.begin(), arr.end());
        int total = 0;
        
        for (int i = 0; i < arr.size() - 2; i++)
        {
            int twoSumTarget = target - arr[i];
            
            int left = i + 1, right = arr.size() - 1;
            
            while (left < right)
            {
                total %= (1000000000 + 7);
                
                if (arr[left] + arr[right] < twoSumTarget)
                {
                    left++;
                }
                else if (arr[left] + arr[right] > twoSumTarget)
                {
                    right--;
                }
                else
                {
                    // we add to total the number of nums[left] * the number of nums right
                    int left_count = 0, left_value = arr[left]; 
                    int right_count = 0, right_value = arr[right];
                    
                    // when we have duplicate in the middle
                    if (left_value == right_value)
                    {
                        total += (right - left + 1)* (right - left) / 2;
                        break;
                    }
                    
                    while (arr[left] == left_value) 
                    {
                        left_count++;
                        left++;
                    }
                    
                    while (arr[right] == right_value) 
                    {
                        right_count++;
                        right--;
                    }
                    
                    // update total
                    total += (right_count * left_count);
                }
            }
        }
        
        return total;
           
    }
};