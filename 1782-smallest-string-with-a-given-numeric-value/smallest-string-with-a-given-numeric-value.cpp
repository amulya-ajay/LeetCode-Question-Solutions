class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int remain = k - n;
        int i = n - 1;
        while (remain) {
           int add = min(remain, 25);
           ans[i] += add;
           remain -= add;
           i--;
        }
        return ans;
    }
};