class Solution {
public:
    int maxArea(vector<int>& ht) {
        int st = 0;
        int end = ht.size()-1;
        int maxArea = 0;

        while(st < end){
            int currArea = min(ht[st], ht[end]) * (end - st);
            maxArea = max(currArea, maxArea);

            if(ht[st] > ht[end])
                end--;
            else
                st++;
        }
        return maxArea;
    }
};