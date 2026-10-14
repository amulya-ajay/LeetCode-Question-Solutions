class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;

        while (num-- != 0) {
            int curr = min(9, sum);
            ans += (curr + '0');
            sum -= curr;
        }

        return sum == 0 ? ans : "";
    }
};