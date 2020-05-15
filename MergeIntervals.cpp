class Solution {
    public:
    vector<vector> merge(vector<vector>& intervals) {
    //base case
        if(intervals.size()==0) return {};
        
     //main code   
        sort(intervals.begin(),intervals.end());
        
        vector temp=intervals[0];
        vector<vector> res;
        for(int i=1; i<intervals.size(); i++)
      {
       
        if(intervals[i][0]<=temp[1])
        {
                temp[1]=max(intervals[i][1],temp[1]);
        }
        else
        {
         res.push_back(temp);
         temp=intervals[i];
          }
      }
    res.push_back(temp);
    return res;
    }
};
