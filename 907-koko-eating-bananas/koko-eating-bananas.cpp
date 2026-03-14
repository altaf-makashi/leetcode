class Solution {
public:
    // Use long long for the sum to prevent overflow on large test cases
    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long total = 0;
        for (int pile : piles) {
            // Standard integer ceiling: (a + b - 1) / b
            total += (1LL * pile + speed - 1) / speed;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; // Start at 1 to avoid division by zero
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // Safety check: mid could be 0 if l was 0
            if (mid == 0) { l = 1; continue; }

            if (calculateTotalHours(piles, mid) <= h) {
                ans = mid;    // This speed is possible, try slower
                r = mid - 1;
            } else {
                l = mid + 1;  // Too slow, must eat faster
            }
        }
        return ans;
    }
};