class Solution {
public:
    string minWindow(string s, string t) {
       int n = s.size(), m = t.size();
        
        unordered_map<char,int>mp;
        for(int i=0; i<m; i++) mp[t[i]]++;
        
        int i=0, j=0, minLen = INT_MAX, start = -1, sz = mp.size(), count = 0;
        while(j < n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count++;
            }
            if(count >= sz){
                while(count >= sz){ 
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        start = i;
                    }
                    if(mp.count(s[i])){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) count--;
                    }
                    i++;
                }
            }
            j++;
        }
        
        
        if(start == -1) return "";
        return s.substr(start, minLen); 
    }
};