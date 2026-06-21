class StockSpanner {
public:
    int i=-1;
    stack<int>st;
    vector<int>count,nums;
    StockSpanner() {
    }
    
    int next(int price) {
        i++;
        count.push_back(1);
        nums.push_back(price);
        while(!st.empty() && nums[i]>=nums[st.top()]){
            count[i]+=count[st.top()];
            st.pop();
        }
        st.push(i);
        return count[i];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */