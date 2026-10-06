class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ms = 0, cs = 0;
        int lt = 0, rt = 0;
        unordered_set<int> seen;

        while (rt < n) {
            while (seen.count(nums[rt])) {
                cs -= nums[lt];
                seen.erase(nums[lt]);
                lt++;
            }

            cs += nums[rt];
            seen.insert(nums[rt]);

            if (rt - lt + 1 == k) {
                ms = max(ms, cs);
                cs -= nums[lt];
                seen.erase(nums[lt]);
                lt++;
            }
            rt++;
        }
        return ms;
    }
};