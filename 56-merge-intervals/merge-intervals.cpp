class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        // sort the array
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals){
            if(ans.size()==0)ans.push_back(it);
            else if(ans.back()[1]>=it[0] && ans.back()[1]<it[1])ans.back()[1]=it[1];
            else if(ans.back()[1]<it[0]) ans.push_back(it);
        }
        return ans;
    }
};