class StockSpanner {
public:
    // We only need the stack and a vector to keep track of prices by their index
    stack<int> st; // Stores indices
    vector<int> nums;
    int i;

    StockSpanner() {
        i = -1;
    }
    
    int next(int price) {
        i++;
        nums.push_back(price);
        
        // Pop elements from the stack while the current price is greater than 
        // or equal to the price at the index on top of the stack
        while (!st.empty() && price >= nums[st.top()]) {
            st.pop();
        }
        
        // If stack is empty, 'price' is greater than all previous prices
        int span = st.empty() ? (i + 1) : (i - st.top());
        
        // Push the current index onto the stack
        st.push(i);
        
        return span;
    }
};