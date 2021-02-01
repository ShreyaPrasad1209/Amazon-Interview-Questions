class Solution {
public:
   bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto v:wordDict){
            st.insert(v);
        }
        vector<int> dp(s.size()+1);
        for(int i=0;i<s.size();i++){
            if(st.find(s.substr(0,i+1))!=st.end()){
                dp[i]=1;
            }
            else{
                dp[i]=0;
                for(int j=0;j<i;j++){
                    string test = s.substr(j+1,i-j);
                    if(dp[j]==1 && st.find(test)!=st.end()){
                        dp[i]=1;
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};
