class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1]; 
        return a[0] > b[0];     // Taller height first
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), comparator);

        vector<vector<int>> ans;
        for (const auto& p : people) {
            ans.insert(ans.begin() + p[1], p);
        }

        return ans;
    }
};