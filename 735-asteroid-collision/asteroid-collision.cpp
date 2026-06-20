class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int num=arr[i];
            if(num>0){
                st.push_back(num);
            }else{
                while(!st.empty() && st.back()>0 && st.back()<abs(num)){
                    st.pop_back();
                }
                if(!st.empty() && st.back()>0 && st.back()==abs(num))st.pop_back();
                else if(!st.empty() && st.back()>abs(num)){
                    continue;
                }else{
                    st.push_back(num);
                }
            }
        }
        return st;
    }
};