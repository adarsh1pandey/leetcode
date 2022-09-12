class Solution {
public:
    long hours(vector<int>&piles, int h, int n)
    {
        long minH=0;
        for(int i=0;i<n;i++)    minH += piles[i]/h + ((piles[i]%h)!=0);
        return minH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=0,ans=0;
        for(int i=0;i<n;i++)    r = max(r,piles[i]);
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(hours(piles,mid,n) <= h)
            {
                ans = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }
        return ans;
    }
};