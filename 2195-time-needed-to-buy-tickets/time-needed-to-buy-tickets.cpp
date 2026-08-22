class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int time = 0;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();

            q.pop();
            p.second--;
            time++;


            if (p.second == 0) {
                if (p.first == k) {
                    return time;
                }
            } else {
                q.push(p);
            }
        }
        return 0;
    }
};