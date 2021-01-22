class Solution {
public:
    
    bool canEatInTime(vector<int>& piles, int K, int H)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
            int div=piles[i]/K;
            hours+=div;
            if(piles[i]%K)
            {
                hours++;
            }
        }
        
        return hours<=H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int left=1, right=*max_element(piles.begin(), piles.end());
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(canEatInTime(piles, mid, H))
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
            return left;
        
    }
};
