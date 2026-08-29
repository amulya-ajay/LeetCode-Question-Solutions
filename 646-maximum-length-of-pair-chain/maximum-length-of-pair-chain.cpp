class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });

        int currEnd = pairs[0][1];
        int chainLen = 1;

        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] > currEnd){
                chainLen++;
                currEnd = pairs[i][1];
            }
        }
        return chainLen;
    }
};