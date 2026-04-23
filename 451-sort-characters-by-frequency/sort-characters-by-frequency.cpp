class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        vector<pair<int, char>> v;
        for (auto it : freq) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans = "";
        for (auto& it : v) {
            ans.append(it.first, it.second);
        }

        return ans;
    }
};