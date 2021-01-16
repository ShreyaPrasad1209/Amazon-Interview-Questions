class Solution {
public:
    string countAndSay(int n) {
        vector<string>res(n+1);
        res[0]="1";
        res[1]="11";
        
        for(int i=2;i<=n;i++)
        {
            string pre=res[i-1];
            string temp = "";
            for(int j=0;j<pre.length();j++)
            {
                int count=1;
                while(j<pre.length()-1 && pre[j]==pre[j+1])
                {
                    count++; j++;
                }
                temp+=to_string(count)+pre[j];
            }
            
            res[i]=temp;
        }
        
        return res[n-1];
    }
};

//LeetCode Link: https://leetcode.com/problems/count-and-say/
//Time Complexity: O(n* m^2)
