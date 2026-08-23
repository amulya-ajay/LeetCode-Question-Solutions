class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> gain(n);
        for (int i = 0; i < n; i++) {
            gain[i] = gas[i] - cost[i];
        }
        vector<int> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + gain[i % n];
        }

        deque<int> dq;
        for(int i = 0; i < 2*n; i++){
            while(!dq.empty() && dq.front() < i - n + 1){
                dq.pop_front();
            }

            while(!dq.empty() && prefix[dq.back()] >= prefix[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= n){
                int st = i - n;
                if(prefix[dq.front()] >= prefix[st]){
                    return st;
                }
            }
        }
        return -1;
    }
};