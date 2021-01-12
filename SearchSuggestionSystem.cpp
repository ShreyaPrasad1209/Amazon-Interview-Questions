class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       sort(products.begin(),products.end());
       vector<vector<string>>ans;
       vector<string>mid_ans;
       string new_str="";
       int c=0; 
       for(int i=0;i<searchWord.size();i++)
       {
           new_str=new_str+searchWord[i];
           c++;
           int n=1;
           for(int i=0;i<products.size();i++){
               string cmp=products[i].substr(0,c);
               if(cmp==new_str && n!=4){
                   mid_ans.push_back(products[i]);
                   n++;
               }
           }
           ans.push_back(mid_ans);
           mid_ans.clear();
       }
       
        return ans;
    }
};

//LeetCode Link: https://leetcode.com/problems/search-suggestions-system/
