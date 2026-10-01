class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lt = 0;
        int rt = nums.size() - 1;

        while (lt < rt) {
            int sum = nums[lt] + nums[rt];

            if (sum == target)
                return {++lt, ++rt};

            else if (sum < target)
                lt++;
            else
                rt--;
        }
        return {};
    }
};