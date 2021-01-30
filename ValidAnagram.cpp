class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++; m[t[i]]--;
        }
       
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second!=0)
            {
               return false; 
            }
        }
        
        return true;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1) because the size of the hash table remains constant. It has a fixed value which is why space has O(1). 
//If the size would have depended on input dynamically then space complexity would have been O(n). 
