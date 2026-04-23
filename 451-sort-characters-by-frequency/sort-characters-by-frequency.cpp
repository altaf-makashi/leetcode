class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        vector<string>bucket(n+1,"");
        for(auto it:mpp){
            int count=it.second;
            char curr=it.first;
            bucket[count].append(count,curr);
        }
        string ans="";
        for (int i = n; i >= 1; i--) {
            if (!bucket[i].empty()) {
                ans += bucket[i];
            }
        }
        return ans;
    }
};