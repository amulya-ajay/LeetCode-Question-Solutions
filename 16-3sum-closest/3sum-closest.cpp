class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int lt = i + 1;
            int rt = n - 1;

            while (lt < rt) {
                int sum = nums[i] + nums[lt] + nums[rt];
                if (abs(target - sum) < abs(target - res))
                    res = sum;
                if (sum == target)
                    return target;
                else if (sum < target)
                    lt++;
                else
                    rt--;
            }
        }
        return res;
    }
};