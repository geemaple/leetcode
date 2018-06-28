class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if (nums.size() == 0){
            return vector<int>();
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> table;
        table.push_back(vector<int>{nums[0]});
        
        
        for (auto i = 1; i < nums.size(); ++i){
    
            vector<int> candidate{nums[i]};
            for (auto j = 0; j < table.size(); ++j){
                if (nums[i] % nums[j] == 0 && candidate.size() < table[j].size() + 1){
                    candidate = table[j];
                    candidate.push_back(nums[i]);
                }
            }
            
            table.push_back(candidate);
        }
        
        // find the longest
        int answer = 0;
        for (auto i = 1; i < table.size(); ++i){
            if (table[answer].size() < table[i].size()){
                answer = i;
            }
        }
        
        return table[answer];
    }
};