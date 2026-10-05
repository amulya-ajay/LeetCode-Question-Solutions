class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int lt = j + 1;
                int rt = n - 1;

                while (lt < rt) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[lt];
                    sum += nums[rt];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[lt], nums[rt]});
                        lt++;
                        rt--;

                        while (lt < rt && nums[lt] == nums[lt - 1])
                            lt++;

                        while (lt < rt && nums[rt] == nums[rt + 1])
                            rt--;
                    } else if (sum < target)
                        lt++;
                    else
                        rt--;
                }
            }
        }

        return res;
    }
};