class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq_num(n);

        for (int i = 0; i < n; i++) {
            sq_num[i] = 1LL * nums[i] * nums[i];
        }
        sort(sq_num.begin(), sq_num.end());
        int k = n / 2;

        long long ans = 0;

        for (int i = 0; i < k; i++)
            ans -= sq_num[i];

        for (int i = k; i < n; i++)
            ans += sq_num[i];

        return ans;
    }
};