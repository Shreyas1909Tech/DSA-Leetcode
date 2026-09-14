class Solution {
public:
    int kadanesMax(vector<int>& nums, int n) {
        int sum = nums[0], maxsum = nums[0];
        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }

    int kadanesMin(vector<int>& nums, int n) {
        int sum = nums[0], minsum = nums[0];
        for (int i = 1; i < n; i++) {
            sum = min(nums[i], sum + nums[i]);
            minsum = min(minsum, sum);
        }
        return minsum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);
        int maxsum = kadanesMax(nums, n);
        int minsum = kadanesMin(nums, n);
        
       
        if (maxsum < 0) {
            return maxsum;
        }
        
        int circularsum = SUM - minsum;
        return max(maxsum, circularsum);
    }
};