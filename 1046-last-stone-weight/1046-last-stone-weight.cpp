class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        
        int n = stones.size();
        
        for (int i = 0; i < n; i++)
        {
            q.push(stones[i]);
        }
        
        while(q.size() != 0 && q.size() != 1)
        {
            int top = q.top();
            q.pop();
            int secondTop = q.top();
            q.pop();
            
            if (top > secondTop)
            {
                top = top - secondTop;
                q.push(top);
            }
        }
        if (q.size() == 0)
            return 0;
        else
            return q.top();
    }
};