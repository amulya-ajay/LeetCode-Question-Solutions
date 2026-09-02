class Solution {
public:
    bool ispossible(vector<int>& nums, int m, int maxSum){
        int currsum = 0;
        int subarr = 1;

        for(int i = 0; i < nums.size(); i++){
            if(currsum + nums[i] > maxSum){
                currsum = nums[i];
                subarr++;
            }
            else{
                currsum += nums[i];
            }
        }
        return subarr <= m;
    }
    int splitArray(vector<int>& nums, int k) {
        int st = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        while(st < end){
            int mid = st + (end - st)/2;

            if(ispossible(nums, k, mid)){
                end = mid;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};