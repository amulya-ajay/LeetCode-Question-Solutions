class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        for(int i = 0; i < img1.size(); i++){
            for(int j = 0; j < img1[0].size(); j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> freq;
        for(int i = 0; i < ones1.size(); i++){
            for(int j = 0; j < ones2.size(); j++){
                int dx = ones2[j].first - ones1[i].first;
                int dy = ones2[j].second - ones1[i].second;
                freq[{dx, dy}]++;
            }
        }
        int high = 0;

        for(auto x : freq){
            high = max(high, x.second);
        }
        return high;
    }
};