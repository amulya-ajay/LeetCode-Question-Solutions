class Solution {
public:
    long long countPairs(vector<string>& words) {
       unordered_map<string, long long> counts;
        long long total_pairs = 0;
        
        for (const string& word : words) {
            string normalized = "";
            int shift = word[0] - 'a';
            
            for (char c : word) {
                int original_val = c - 'a';
                int normalized_val = (original_val - shift + 26) % 26;
                normalized += (char)(normalized_val + 'a');
            }
            
            total_pairs += counts[normalized];
            counts[normalized]++;
        }
        
        return total_pairs;
    }
};